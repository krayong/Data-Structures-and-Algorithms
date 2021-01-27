#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1
 * Description:
    Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.

    Examples :

    Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5

    Output : 1
    Explanation : 
            2     
          /   \    
         4     5   is the duplicate sub-tree.
 
    Input : 
               1
             /   \ 
           2       3

    Output: 0
    Explanation: There is no duplicate sub-tree in the given binary tree.
    
    Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one.
 * Resources:
 *  https://www.geeksforgeeks.org/check-binary-tree-contains-duplicate-subtrees-size-2/
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

    string inorder(Node *root, unordered_map<string, int> &um)
    {
        if (root == NULL)
            return "";

        string s;

        auto temp_left = inorder(root->left, um);
        if (temp_left != "")
            s += temp_left;

        s += root->data;

        auto temp_right = inorder(root->right, um);
        if (temp_right != "")
            s += temp_right;

        if (s.length() > 1)
            um[s]++;

        return s;
    }

    bool check_dup_subtree()
    {
        unordered_map<string, int> um;
        inorder(this->root, um);

        for (auto it : um)
            if (it.se > 1)
                return true;

        return false;
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

        if (bt.check_dup_subtree())
            cout << "Tree contains duplicate subtree\n";
        else
            cout << "Tree does not contain duplicate subtree\n";
    }

    return 0;
}