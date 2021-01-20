#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/
 * Description:
    Construct a binary tree from a string consisting of parenthesis and integers. 
    The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root’s value and a pair of parenthesis contains a child binary tree with the same structure. Always start to construct the left child node of the parent first if it exists.

    Examples: 

    Input : "1(2)(3)" 
    Output : 1 2 3
    Explanation :
           1
          / \
         2   3
    Explanation: first pair of parenthesis contains 
    left subtree and second one contains the right 
    subtree. Preorder of above tree is "1 2 3".  

    Input : "4(2(3)(1))(6(5))"
    Output : 4 2 3 1 6 5
    Explanation :
           4
         /   \
        2     6
       / \   / 
      3   1 5   
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

    int find_index_first_end(string str, int s, int e)
    {
        if (s > e)
            return -1;

        int open_bkt_count = 0;
        for (int i = s; i <= e; i++)
        {
            if (str[i] == '(')
                open_bkt_count++;
            else if (str[i] == ')')
            {
                if (open_bkt_count > 0)
                {
                    open_bkt_count--;
                    if (open_bkt_count == 0)
                        return i;
                }
            }
        }

        return -1;
    }

    Node* tree_from_string(string str, int s, int e)
    {
        if (s > e) return NULL;

        Node *new_node = new Node(str[s] - '0');
        int index = -1;

        if (s + 1 <= e && str[s + 1] == '(')
            index = find_index_first_end(str, s + 1, e);
        
        if (index != -1)
        {
            new_node->left = tree_from_string(str, s + 2, index - 1);
            new_node->right = tree_from_string(str, index + 2, e - 1);
        }

        return new_node;
    }

    void build_tree(string str)
    {
        this->root = tree_from_string(str, 0, str.length() - 1);
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
        string str;
        ss(str);

        BinaryTree bt;
        bt.build_tree(str);

        cout << "Inorder traversal:\n";
        bt.print_in_order();
    }

    return 0;
}