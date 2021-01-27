#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/sum-tree/1
 * Description:
    Given a Binary Tree. Check whether it is a Sum Tree or not.
    A Binary Tree is a Sum Tree in which value of each node x is equal to sum of nodes 
    present in its left subtree and right subtree . 
    An empty tree is also a Sum Tree as sum of an empty tree can be considered to be 0. 
    A leaf node is also considered as a Sum Tree.

    Examples:

    Input:
        3
      /   \    
     1     2

    Output: 1
    Explanation: The given tree is a sum tree so return a boolean true.

    Input:

            10
          /   \
        20     30
      /   \ 
    10    10

    Output: 0
    Explanation: 
    The given tree is not a sum tree. For the root node, sum of elements in left subtree is 40 
    and sum of elements in right subtree is 30. Root element = 10 which is not equal to 30+40.

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(Height of the Tree)

    Constraints:
    1 ≤ number of nodes ≤ 104
 * Resources:
 *  https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-sumtree/
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

    // int calc_sum(Node *root)
    // {
    //     if (root == NULL) return 0;
    //
    //     return calc_sum(root->left) + root->data + calc_sum(root->right);
    // }

    bool check_sum_tree(Node *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return true;

        if (check_sum_tree(root->left) && check_sum_tree(root->right))
        {
            int lsum, rsum;

            if (root->left == NULL)
                lsum = 0;
            else if (root->left->left == NULL && root->left->right == NULL)
                lsum = root->left->data;
            else
                lsum = 2 * root->left->data; // since left is not a leaf node, sum of the left subtree for current node
                                             // is twice the data in left node as it is the sum of it's subtrees

            if (root->right == NULL)
                rsum = 0;
            else if (root->right->left == NULL && root->right->right == NULL)
                rsum = root->right->data;
            else
                rsum = 2 * root->right->data; // since right is not a leaf node, sum of the right subtree for current
                                              // node is twice the data in right node as it is the sum of it's subtrees

            return (root->data == lsum + rsum);
        }
        return false;
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

        BinaryTree bt;
        bt.build_level_order(n);

        cout << "Inorder traversal:\n";
        bt.print_in_order();

        if (bt.check_sum_tree(bt.root))
            ps("YES");
        else
            ps("NO");
    }

    return 0;
}