#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link :
 *  https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
 *  https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
 * Description:
    Given a Binary Tree, print Left view of it. 
    Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. 

    Examples:

    Input:
       1
     /  \
    3    2
    Output: 
    Left view: 1 3
    Right view: 1 2

    Input:
         10
        /  \
      20    30
     /  \
    40  50 
    Output: 
    Left view: 10 20 40
    Right view: 10 30 50

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(N).

    Constraints:
    0 <= Number of nodes <= 100
    1 <= Data of a node <= 1000
 * Resources:
 *  https://www.geeksforgeeks.org/print-left-view-binary-tree/
 *  https://www.geeksforgeeks.org/print-right-view-binary-tree-2/
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

    vi left_view()
    {
        queue<Node*> q;
        q.push(this->root);

        vi v;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 1; i <= n; i++)
            {
                Node *temp = q.front();
                q.pop();

                if (i == 1)
                    v.pb(temp->data);
                
                if (temp->left != NULL)
                    q.push(temp->left);

                if (temp->right != NULL)
                    q.push(temp->right);
            }
        }

        return v;
    }

    vi right_view()
    {
        queue<Node *> q;
        q.push(this->root);

        vi v;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 1; i <= n; i++)
            {
                Node *temp = q.front();
                q.pop();

                if (i == n)
                    v.pb(temp->data);

                if (temp->left != NULL)
                    q.push(temp->left);

                if (temp->right != NULL)
                    q.push(temp->right);
            }
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

        cout << "Left view:\n";
        vi v = bt.left_view();
        for (int i : v)
            cout << i << " ";
        cout << "\n";

        cout << "Right view:\n";
        v = bt.right_view();
        for (int i : v)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}