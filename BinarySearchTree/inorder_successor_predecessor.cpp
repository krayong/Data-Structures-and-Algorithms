#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
 * Description:
    There is BST given with root node with key part as integer only. 
    You need to find the inorder successor and predecessor of a given key. 
    In case, if the either of predecessor or successor is not found print -1.

    Input:
    The first line of input contains an integer T denoting the number of test cases. 
    Then T test cases follow. Each test case contains n denoting the number of edges of the BST. 
    The next line contains the edges of the BST. The last line contains the key.

    Output:
    Print the predecessor followed by successor for the given key. 
    If the predecessor or successor is not found print -1.

    Constraints:
    1<=T<=100
    1<=n<=100
    1<=data of node<=100
    1<=key<=100

    Example:
    Input:
    2
    6
    50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
    65
    6
    50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
    100

    Output:
    60 70
    80 -1
 * Resources:
 *  https://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/
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

    void inorder_successor_predecessor(Node *root, Node *&pre, Node *&succ, int key)
    {
        if (root == NULL)
            return;

        if (root->data < key)
        {
            pre = root;
            inorder_successor_predecessor(root->right, pre, succ, key);
        }
        else if (root->data > key)
        {
            succ = root;
            inorder_successor_predecessor(root->left, pre, succ, key);
        }
        else
        {
            if (root->left)
            {
                Node *temp = root->left;
                while (temp->right)
                    temp = temp->right;
                pre = temp;
            }

            if (root->right)
            {
                Node *temp = root->right;
                while (temp->left)
                    temp = temp->left;
                succ = temp;
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

        int key;
        si(key);

        cout << "Inorder traversal:\n";
        bst.print_in_order();

        Node *pre = NULL, *succ = NULL;
        bst.inorder_successor_predecessor(bst.root, pre, succ, key);

        cout << "Inorder predecessor is: " << pre->data << "\n";
        cout << "Inorder successor is: " << succ->data << "\n";
    }

    return 0;
}