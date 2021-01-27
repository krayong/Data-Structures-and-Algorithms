#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/
 * Description:
    Given a binary tree with a value associated with each node, 
    we need to choose a subset of these nodes such that the sum of chosen nodes 
    is maximum under a constraint that no two chosen node in the subset 
    should be directly connected that is, if we have taken a node in our sum 
    then we can’t take it’s any children in consideration and vice versa.

    Examples: https://media.geeksforgeeks.org/wp-content/uploads/nodeSubsetWithMaxSum.png
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

    pii max_sum_no_adjacent(Node *root)
    {
        if (root == NULL)
            return mp(0, 0);

        auto ls = max_sum_no_adjacent(root->left);
        auto rs = max_sum_no_adjacent(root->right);

        pii sum;

        sum.fi = root->data +   // including current node
                 ls.se + rs.se; // excluding childs

        sum.se = max(ls.fi, ls.se) + max(rs.fi, rs.se); // excluding current node

        return sum;
    }

    int max_sum_no_adjacent()
    {
        auto sum = max_sum_no_adjacent(this->root);
        return max(sum.fi, sum.se);
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

        cout << "Maximum sum excluding adjacent nodes: " << bt.max_sum_no_adjacent() << "\n";
    }

    return 0;
}