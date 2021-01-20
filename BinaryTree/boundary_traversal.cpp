#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
 * Description:
    Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

    Left boundary nodes: defined as the path from the root to the left-most node ie- 
    the leaf node you could reach when you always travel preferring the left subtree over the right subtree.

    Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.

    Reverse right boundary nodes: defined as the path from the right-most node to the root. 
    The right-most node is the leaf node you could reach when you always travel preferring 
    the right subtree over the left subtree. Exclude the root from this as it 
    was already included in the traversal of left boundary nodes.
    
    Note: If the root doesn't have a left subtree or right subtree, 
    then the root itself is the left or right boundary. 

    Examples:

    Input:
           1
         /   \
        2     3    
    Output: 1 2 3

    Input:
                  20
                 /  \
               8     22
             /  \     \
            4   12     25
          /  \ 
        10   14 

    Output: 20 8 4 10 14 25 22
    Explanation: https://contribute.geeksforgeeks.org/wp-content/uploads/boundary.png

    Expected Time Complexity: O(N). 
    Expected Auxiliary Space: O(Height of the Tree).

    Constraints:
    1 ≤ Number of nodes ≤ 105
    1 ≤ Data of a node ≤ 105
 * Resources:
 *  https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
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

    void left_boundary(Node *root, vi &res)
    {
        if (root == NULL)
            return;

        if (root->left != NULL)
        {
            res.pb(root->data);
            left_boundary(root->left, res);
        }
        else if (root->right != NULL)
        {
            res.pb(root->data);
            left_boundary(root->right, res);
        }
    }

    void leaf_nodes(Node *root, vi &res)
    {
        if (root == NULL)
            return;

        leaf_nodes(root->left, res);

        if (root->left == NULL && root->right == NULL)
        {
            res.pb(root->data);
            return;
        }

        leaf_nodes(root->right, res);
    }

    void right_boundary(Node *root, vi &res)
    {
        if (root == NULL)
            return;

        if (root->right != NULL)
        {
            right_boundary(root->right, res);
            res.pb(root->data);
        }
        else if (root->left != NULL)
        {
            right_boundary(root->left, res);
            res.pb(root->data);
        }
    }

    vi boundary_traversal()
    {
        vi res;
        res.pb(this->root->data);

        left_boundary(this->root->left, res);
        leaf_nodes(this->root, res);
        right_boundary(this->root->right, res);

        return res;
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

        cout << "Boundary traversal:\n";
        vi v = bt.boundary_traversal();
        for (int i : v)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}