#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/
 * Description:
    A binary tree and a number k are given. Print every path 
    in the tree with sum of the nodes in the path as k.
    A path can start from any node and end at any node and 
    must be downward only, i.e. they need not be root node and leaf node; 
    and negative numbers can also be there in the tree.

    Examples:

    Input : k = 5  
            Root of below binary tree:
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
                       
    Output :
    3 2 
    3 1 1 
    1 3 1 
    4 1 
    1 -1 4 1 
    -1 4 2 
    5 
    1 -1 5 
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

    void print_k_paths(Node *root, vi &path, vvi &paths, int k)
    {
        if (root == NULL)
            return;

        path.pb(root->data);
        print_k_paths(root->left, path, paths, k);
        print_k_paths(root->right, path, paths, k);

        int sum = 0;
        for(int i = path.size() - 1; i >= 0; i--)
        {
            sum += path[i];

            if (sum == k)
                paths.pb(vi(path.begin() + i, path.end()));
        }

        path.pop_back();
    }

    vvi print_k_paths(int k)
    {
        vvi paths;
        vi path;

        print_k_paths(this->root, path, paths, k);

        return paths;
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

        int k;
        si(k);

        cout << "Inorder traversal:\n";
        bt.print_in_order();

        auto paths = bt.print_k_paths(k);
        cout << "Paths are:\n";
        fo(i, 0, paths.size())
        {
            fo(j, 0, paths[i].size())
            {
                cout << paths[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}