#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/kth-ancestor-node-binary-tree/
 * Description:
    Given a binary tree in which nodes are numbered from 1 to n. 
    Given a node and a positive integer K. We have to print the K-th ancestor 
    of the given node in the binary tree. If there does not exist any such ancestor then print -1.
    
    Example:
    https://media.geeksforgeeks.org/wp-content/uploads/tree122-1.gif

    2nd ancestor of node 4 and 5 is 1. 3rd ancestor of node 4 will be -1. 

 * Resources:
 *  https://www.geeksforgeeks.org/kth-ancestor-node-binary-tree-set-2/
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

    void bfs(int parent[])
    {
        parent[this->root->data] = -1;

        queue<Node *> q;
        q.push(this->root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left != NULL)
            {
                parent[temp->left->data] = temp->data;
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                parent[temp->right->data] = temp->data;
                q.push(temp->right);
            }
        }
    }

    int find_kth_ancestor(int size, int node_num, int k)
    {
        int parent[size + 1] = {0};

        bfs(parent);

        int count = 0;
        while (node_num != -1)
        {
            node_num = parent[node_num];
            ++count;

            if (count == k)
                break;
        }

        return node_num;
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

        int node_num, k;
        si(node_num);
        si(k);

        cout << "Inorder traversal:\n";
        bt.print_in_order();

        cout << "K'th ancestor of " << node_num << "th node with k as " << k << " is: " << bt.find_kth_ancestor(n, node_num, k);
    }

    return 0;
}