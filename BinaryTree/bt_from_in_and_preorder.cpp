#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/construct-tree-1/1
 * Description:
    Given 2 Arrays of Inorder and Preorder traversal. Construct a tree and print the Postorder traversal. 

    Examples:

    Input:
    N = 4
    inorder[] = {1 6 8 7}
    preorder[] = {1 6 7 8}
    Output: 8 7 6 1
    Example 2:

    Input:
    N = 6
    inorder[] = {3 1 4 0 5 2}
    preorder[] = {0 1 3 4 2 5}
    Output: 3 4 1 5 2 0
    Explanation: The tree will look like
           0
        /     \
       1       2
     /   \    /
    3    4   5

    Expected Time Complexity: O(N*N).
    Expected Auxiliary Space: O(N).

    Constraints:
    1<=Number of Nodes<=1000
 * Resources:
 *  https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
 * 
*************************************************************************************************************/

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define ss(s) getline(cin, s)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ps(s) cout << s << "\n"
#define ll long long
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define rof(i, k, n) for (ll i = k; i >= n; i--)
#define deb(x) cout << #x << "=" << x << "\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define set(x, i) memset(x, i, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(a, it) for (auto it = a.begin(); it != a.end(); it++)
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

struct BinaryTree
{
    Node *root;
    int size;

    BinaryTree()
    {
        root = NULL;
        size = 0;
    }

    void print_in_order()
    {
        print_in_order_util(this->root);
        cout << "\n";
    }

    void print_pre_order()
    {
        print_pre_order_util(this->root);
        cout << "\n";
    }

    void print_post_order()
    {
        print_post_order_util(this->root);
        cout << "\n";
    }

    void build_level_order(int n)
    {
        this->size = n;

        int arr[n] = {0};
        fo(i, 0, n) si(arr[i]);

        this->root = build_level_order_util(arr, this->root, 0);
    }

    Node *build_tree_util(int inorder[], int preorder[], int l, int h, unordered_map<int, int> &um)
    {
        static int pre_index = 0;

        if (l > h)
            return NULL;

        Node *root = new Node(preorder[pre_index++]);

        if (l == h)
            return root;

        int idx = um[root->data];

        root->left = build_tree_util(inorder, preorder, l, idx - 1, um);
        root->right = build_tree_util(inorder, preorder, idx + 1, h, um);

        return root;
    }

    void build_tree(int inorder[], int preorder[], int n)
    {
        unordered_map<int, int> um;
        fo(i, 0, n) um[inorder[i]] = i;

        this->root = build_tree_util(inorder, preorder, 0, n - 1, um);
    }

private:
    void print_in_order_util(Node *node)
    {
        if (node != NULL)
        {
            print_in_order_util(node->left);
            cout << node->data << ", ";
            print_in_order_util(node->right);
        }
    }

    void print_pre_order_util(Node *node)
    {
        if (node != NULL)
        {
            cout << node->data << ", ";
            print_pre_order_util(node->left);
            print_pre_order_util(node->right);
        }
    }

    void print_post_order_util(Node *node)
    {
        if (node != NULL)
        {
            print_post_order_util(node->left);
            print_post_order_util(node->right);
            cout << node->data << ", ";
        }
    }

    Node *build_level_order_util(int arr[], Node *node, int i)
    {
        if (i < this->size)
        {
            node = new Node(arr[i]);

            node->left = build_level_order_util(arr, node->left, 2 * i + 1);
            node->right = build_level_order_util(arr, node->right, 2 * i + 2);
        }

        return node;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t;
    si(t);

    while (t--)
    {
        int n;
        si(n);

        int inorder[n] = {0};
        fo(i, 0, n) si(inorder[i]);

        int preorder[n] = {0};
        fo(i, 0, n) si(preorder[i]);

        BinaryTree bt;
        bt.build_tree(inorder, preorder, n);

        cout << "Postorder traversal:\n";
        bt.print_post_order();
    }

    return 0;
}