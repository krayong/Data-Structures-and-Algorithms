#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
 * Description:
    Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

    Examples:

    Input:
            3
         /   \
        2     1
    Output: 3 1 2

    Input:
                7
             /    \
           9       7
         /  \     /   
        8    8   6     
      /  \
    10   9 
    Output: 7 7 9 8 8 6 9 10 
    
    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(N).

    Constraints:
    1 <= N <= 104
 * Resources:
 *  https://www.geeksforgeeks.org/zigzag-tree-traversal/
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

    vi zig_zag_traversal()
    {
        deque<Node *> dq;
        dq.push_back(this->root);

        vi v;
        bool rtl = false; // to reverse it after adding root(only 1 element)

        while (!dq.empty())
        {
            int size = dq.size();

            if (rtl)
                for (auto it = dq.rbegin(); it != dq.rend(); ++it)
                    v.pb((*it)->data);
            else
                for (auto it = dq.begin(); it != dq.end(); ++it)
                    v.pb((*it)->data);

            while (size-- > 0)
            {
                Node *temp = dq.front();
                dq.pop_front();

                if (temp->left != NULL)
                    dq.pb(temp->left);

                if (temp->right != NULL)
                    dq.pb(temp->right);
            }

            rtl = !rtl;
        }

        return v;
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

        cout << "In order traversal:\n";
        bt.print_in_order();

        cout << "Zig zag traversal:\n";
        vi v = bt.zig_zag_traversal();
        for (int i : v)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}