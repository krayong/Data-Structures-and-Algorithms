#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : 
 *  https://www.geeksforgeeks.org/flatten-bst-to-sorted-list-increasing-order/
 *  https://www.geeksforgeeks.org/flatten-bst-to-sorted-list-decreasing-order/
 * Description:
    Given a binary search tree, the task is to flatten it to a sorted list. 
    Precisely, the value of each node must be lesser(or greater) than the values of all the 
    nodes at its right, and its left node must be NULL after flattening. 
    We must do it in O(H) extra space where ‘H’ is the height of BST.

    Examples:
    Input: 
          5 
        /   \ 
       3     7 
      / \   / \ 
     2   4 6   8
    Output: 
    Increasing: 2 3 4 5 6 7 8
    Decreasing: 8 7 6 5 4 3 2

    Input:
      1
       \
        2
         \
          3
           \
            4
             \
              5
    Output: 
    Increasing: 1 2 3 4 5
    Decreasing: 5 4 3 2 1
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

    void print(Node *parent)
    {
        Node *curr = parent;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
    }

    void inorder(Node *curr, Node *&prev)
    {
        if (curr == NULL)
            return;

        inorder(curr->left, prev);

        prev->left = NULL;
        prev->right = curr;
        prev = curr;

        inorder(curr->right, prev);
    }

    void rev_inorder(Node *curr, Node *&prev)
    {
        if (curr == NULL)
            return;

        rev_inorder(curr->right, prev);

        prev->left = NULL;
        prev->right = curr;
        prev = curr;

        rev_inorder(curr->left, prev);
    }

    void flatten()
    {
        Node *dummy = new Node(-1);
        Node *prev = dummy;

        inorder(this->root, prev); // For increasing
        // rev_inorder(this->root, prev); // For decreasing

        prev->left = NULL;
        prev->right = NULL;

        print(dummy->right);

        delete dummy;
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

        cout << "Flattened list: ";
        bst.flatten();

        cout << "\n";
    }

    return 0;
}