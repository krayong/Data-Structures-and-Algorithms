#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : 
 *  https://practice.geeksforgeeks.org/problems/level-order-traversal/1
 *  https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1
 * Description:
    Given a binary tree, find its level order traversal and reverse level order traversal.
    Level order traversal of a tree is breadth-first traversal for the tree.

    Examples:

    Input:
        1
     /   \ 
    3     2
    Output:
    1 3 2
    3 2 1

    Input:
           10
         /   \
       20   30
     /   \
    40   50
    Output:
    10 20 30 40 50
    40 50 20 30 10

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(N)

    Constraints:
    1 <= Number of nodes<= 104
    1 <= Data of a node <= 104
 * Resources:
 *  https://www.geeksforgeeks.org/level-order-tree-traversal/
 *  https://www.geeksforgeeks.org/reverse-level-order-traversal/
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

    vi level_order_traversal()
    {
        vi v;

        queue<Node *> q;
        q.push(this->root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            v.pb(temp->data);

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }

        return v;
    }

    vi reverse_level_order_traversal()
    {
        queue<Node *> q;
        stack<int> st;

        q.push(this->root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            st.push(temp->data);

            if (temp->right != NULL)
                q.push(temp->right);

            if (temp->left != NULL)
                q.push(temp->left);
        }

        vi v;
        while (!st.empty())
        {
            v.pb(st.top());
            st.pop();
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

        cout << "Level order traversal:\n";
        vi v = bt.level_order_traversal();
        for (int i : v)
            cout << i << " ";
        cout << "\n";

        cout << "Reverse level order traversal:\n";
        v = bt.reverse_level_order_traversal();
        for (int i : v)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}