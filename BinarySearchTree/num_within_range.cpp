#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/
 * Description:
    Given a Binary Search Tree (BST) and a range l-h(inclusive), count 
    the number of nodes in the BST that lie in the given range.

    Examples:
    Input:
          10
         /  \
        5    50
       /    /  \
      1    40  100
    l = 5, h = 45
    Output: 3
    Explanation: 5 10 40 are the node in the range

    Input:
          5
        /  \
       4    6
      /      \
     3        7
    l = 2, h = 8
    Output: 5
    Explanation: All the nodes are in the given range.
    
    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(Height of the BST).

    Constraints:
    1 <= Number of nodes <= 100
    1 <= l < h < 103
 * Resources:
 *  https://www.geeksforgeeks.org/count-bst-nodes-that-are-in-a-given-range/
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

struct BinarySearchTree
{
    Node *root;
    int size;

    BinarySearchTree()
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

    void build_tree(int n)
    {
        this->size = n;

        fo(i, 0, n)
        {
            int temp;
            si(temp);
            this->root = insert(this->root, temp);
        }
    }

    int num_nodes(int l, int h)
    {
        return num_nodes(this->root, l, h);
    }

    int num_nodes(Node *root, int l, int h)
    {
        if (root == NULL)
            return 0;
        else if (root->data < l)
            return num_nodes(root->right, l, h);
        else if (root->data > h)
            return num_nodes(root->left, l, h);
        else
            return 1 + num_nodes(root->left, l, h) + num_nodes(root->right, l, h);
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

    Node *insert(Node *root, int value)
    {
        if (root == NULL)
            return new Node(value);
        else if (root->data < value)
            root->right = insert(root->right, value);
        else
            root->left = insert(root->left, value);

        return root;
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

        BinarySearchTree bst;
        bst.build_tree(n);

        int l, h;
        si(l), si(h);

        cout << "Inorder traversal:\n";
        bst.print_in_order();

        cout << "Number of nodes between " << l << " and " << h << " are: " << bst.num_nodes(l, h) << "\n";
    }

    return 0;
}