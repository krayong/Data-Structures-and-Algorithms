#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/
 * Description:
    Given a BST (Binary Search Tree) that may be unbalanced, 
    convert it into a balanced BST that has minimum possible height.

    Examples :

    Input:
           30
          /
         20
        /
       10
    Output:
         20
       /   \
     10     30

    Input:
             4
            /
           3
          /
         2
        /
       1
    Output:
          3            3           2
        /  \         /  \        /  \
       1    4   OR  2    4  OR  1    3   OR ..
        \          /                   \
         2        1                     4 

    Input:
              4
            /   \
           3     5
          /       \
         2         6 
        /           \
       1             7
    Output:
           4
        /    \
       2      6
     /  \    /  \
    1    3  5    7 
 * Resources:
 *  
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

    void create_inorder(Node *root, vector<Node *> &inorder)
    {
        if (root != NULL)
        {
            create_inorder(root->left, inorder);
            inorder.pb(root);
            create_inorder(root->right, inorder);
        }
    }

    Node *convert_to_balanced_tree(vector<Node *> &inorder, int lo, int hi)
    {
        if (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            Node *root = inorder[mid];

            root->left = convert_to_balanced_tree(inorder, lo, mid - 1);
            root->right = convert_to_balanced_tree(inorder, mid + 1, hi);

            return root;
        }
        else
            return NULL;
    }

    void convert_to_balanced_tree()
    {
        vector<Node *> inorder;
        create_inorder(this->root, inorder);

        this->root = convert_to_balanced_tree(inorder, 0, inorder.size() - 1);
    }

    int height()
    {
        return height(this->root);
    }

    int height(Node *root)
    {
        if (root == NULL)
            return 0;
        else
            return 1 + max(height(root->left), height(root->right));
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

        cout << "Inorder traversal before conversion:\n";
        bst.print_in_order();

        cout << "Height of tree before conversion is: " << bst.height() << "\n";

        bst.convert_to_balanced_tree();

        cout << "Inorder traversal after conversion:\n";
        bst.print_in_order();

        cout << "Height of tree after conversion is: " << bst.height() << "\n";
    }

    return 0;
}