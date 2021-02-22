#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
 * Description:
    Using Morris Traversal, we can traverse the tree without using stack and recursion. 
    The idea of Morris Traversal is based on Threaded Binary Tree. In this traversal, 
    we first create links to Inorder successor and print the data using these links, 
    and finally revert the changes to restore original tree. 


    1. Initialize current as root 
    2. While current is not NULL
    If the current does not have left child
        a) Print current’s data
        b) Go to the right, i.e., current = current->right
    Else
        a) Find rightmost node in current left subtree OR
                node whose right child == current.
            If we found right child == current
                Go to the right, i.e. current = curent->right
            Else
                a) Make current as the right child of that rightmost 
                    node we found; and 
                b) Go to this left child, i.e., current = current->left


    Although the tree is modified through the traversal, it is reverted back to its 
    original shape after the completion. Unlike Stack based traversal, no extra space 
    is required for this traversal.
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

    void morris_travel()
    {
        Node *curr = this->root, *pre = NULL;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                cout << curr->data << " ";
                curr = curr->right;
            }
            else
            {
                pre = curr->left;
                while (pre->right != NULL && pre->right != curr)
                    pre = pre->right;

                if (pre->right == NULL)
                {
                    pre->right = curr;
                    curr = curr->left;
                }
                else
                {
                    pre->right = NULL;
                    cout << curr->data << " ";
                    curr = curr->right;
                }
            }
        }
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

        cout << "Inorder Recursive Traversal:\n";
        bst.print_in_order();

        cout << "Inorder Morris Traversal:\n";
        bst.morris_travel();
    }

    return 0;
}