#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1
 * Description:
    Given a Binary Search Tree. The task is to find the minimum element in this given BST.

    Examples:

    Input:
           5
         /    \
        4      6
       /        \
      3          7
     /
    1
    Output: 1

    Input:
             9
              \
               10
                \
                 11
    Output: 9
    
    Expected Time Complexity: O(Height of the BST)
    Expected Auxiliary Space: O(Height of the BST).

    Constraints:
    1 <= N <= 104
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

    int min_ele()
    {
        if (root == NULL)
            return INT_MAX;
        else
            return min_ele(this->root);
    }

    int min_ele(Node *root)
    {
        if (root->left == NULL)
            return root->data;
        else
            return min_ele(root->left);
    }

    int max_ele()
    {
        if (root == NULL)
            return INT_MIN;
        else
            return max_ele(this->root);
    }

    int max_ele(Node *root)
    {
        if (root->right == NULL)
            return root->data;
        else
            return max_ele(root->right);
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

        cout << "Inorder traversal:\n";
        bst.print_in_order();

        cout << "Minimum element of BST is: " << bst.min_ele() << "\n";
        cout << "Maximum element of BST is: " << bst.max_ele() << "\n";
    }

    return 0;
}