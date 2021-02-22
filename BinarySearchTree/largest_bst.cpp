#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/largest-bst/
 * Description:
    Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.

    Examples:
    Input:
            1
          /   \
         4     4
       /   \
      6     8
    Output: 1
    Explanation: 
    There's no sub-tree with size greater than 1 which forms a BST. All the
    leaf Nodes are the BSTs with size equal to 1.

    Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2 
    Output: 2
    Explanation: 
    The following sub-tree is a BST of size 2: 
       2
        \ 
         8

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(Height of the BST).

    Constraints:
    1 <= Number of nodes <= 100000
    1 <= Data of a node <= 1000000
 * Resources:
 *  https://www.geeksforgeeks.org/find-the-largest-subtree-in-a-tree-that-is-also-a-bst/
 *  https://www.geeksforgeeks.org/largest-bst-binary-tree-set-2/
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

    struct Info
    {
        int size, min, max, bst_size;
        bool is_bst;

        Info()
        {
        }

        Info(int size, int min, int max, int bst_size, bool is_bst)
        {
            this->size = size;
            this->min = min;
            this->max = max;
            this->bst_size = bst_size;
            this->is_bst = is_bst;
        }
    };

    Info subtree_bst_size(Node *root)
    {
        if (root == NULL)
            return Info(0, INT_MAX, INT_MIN, 0, true);
        else if (root->left == NULL && root->right == NULL)
            return Info(1, root->data, root->data, 1, true);

        auto lt = subtree_bst_size(root->left), rt = subtree_bst_size(root->right);

        Info res;
        res.size = 1 + lt.size + rt.size;

        if (lt.is_bst && rt.is_bst && lt.max < root->data && rt.min > root->data)
        {
            res.min = min(root->data, min(lt.min, rt.min));
            res.max = max(root->data, max(lt.max, rt.max));

            res.bst_size = res.size;
            res.is_bst = true;
        }
        else
        {
            res.bst_size = max(lt.bst_size, rt.bst_size);
            res.is_bst = false;
        }
        return res;
    }

    int subtree_bst_size()
    {
        return subtree_bst_size(this->root).bst_size;
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

        cout << "Largest BST subtree is of size: " << bt.subtree_bst_size() << "\n";
    }

    return 0;
}