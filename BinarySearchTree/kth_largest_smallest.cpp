#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/
 * Description:
    Given a Binary search tree. Find the Kth largest and the Kth smallest 
    element without doing any modification in Binary Search Tree.

    Examples:

    Input:
          4
        /   \
       2     9
    k = 2 
    Output: 
    Kth Largest: 4
    Kth Smallest: 4

    Input:
       9
        \ 
          10
    K = 1
    Output: 
    Kth Largest: 10
    Kth Smallest: 9

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(1)

    Constraints:
    1 <= N <= 1000
    1 <= K <= N
 * Resources:
 *  https://www.geeksforgeeks.org/kth-largest-element-in-bst-when-modification-to-bst-is-not-allowed/
 *  https://www.geeksforgeeks.org/find-k-th-smallest-element-in-bst-order-statistics-in-bst/
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

    int kth_largest(int k)
    {
        return kth_largest(this->root, k);
    }

    int kth_largest(Node *root, int &k)
    {
        if (root == NULL || k < 0)
            return INT_MAX;

        int num1 = kth_largest(root->right, k);

        --k;
        if (k == 0)
            return root->data;

        int num2 = kth_largest(root->left, k);

        return min(num1, num2);
    }

    int kth_smallest(int k)
    {
        return kth_smallest(this->root, k);
    }

    int kth_smallest(Node *root, int &k)
    {
        if (root == NULL || k < 0)
            return INT_MAX;

        int num1 = kth_smallest(root->left, k);

        --k;
        if (k == 0)
            return root->data;

        int num2 = kth_smallest(root->right, k);

        return min(num1, num2);
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

        int k;
        si(k);

        cout << "Inorder traversal:\n";
        bst.print_in_order();

        int val = bst.kth_largest(k);
        cout << "Kth largest element of BST is: " << val << "\n";

        val = bst.kth_smallest(k);
        cout << "Kth smallest element of BST is: " << val << "\n";
    }

    return 0;
}