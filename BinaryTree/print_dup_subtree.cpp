#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1
 * Description:
    Given a binary tree of size N, your task is to complete the function printAllDups(), 
    that finds and prints all duplicate subtrees from the given binary tree.
    For each duplicate subtrees, you only need to print the root node value of any one of them.
    Two trees are duplicate if they have the same structure with same node values.

    Example:

    Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5

    Output : 2
    Explanation : 
            2     
          /   \    
         4     5   is the duplicate sub-tree.
 
    Input : 
               1
             /   \ 
           2       3

    Output: -1
    Explanation: There is no duplicate sub-tree in the given binary tree.
    
    Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one.

    Input:
    The function takes a single argument as input, the reference pointer to the root node of the binary tree.
    There will be T, test cases and for each test case the function will be called separately.

    Output:
    The function should print space separated root node value of all the duplicate subtrees. 
    If no duplicate subtree is present in the binary tree print "-1 ".

    Constraints:
    1<=T<=100
    1<=N<=100
 * Resources:
 *  https://www.geeksforgeeks.org/find-duplicate-subtrees/
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

    string inorder(Node *root, unordered_map<string, pair<int, int>> &um)
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

        auto find_res = um.find(s);
        if (find_res != um.end())
            um[s].se++;
        else
            um.insert(mp(s, mp(root->data, 1)));

        return s;
    }

    vi check_dup_subtree()
    {
        unordered_map<string, pair<int, int>> um;
        inorder(this->root, um);

        bool found = false;
        vi result;
        for (auto it : um)
        {
            auto res = it.se;
            if (res.se > 1)
            {
                result.pb(res.fi);
                found = true;
            }
        }

        if (found == false)
            result.pb(-1);
        else
            sortall(result);

        return result;
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

        auto res = bt.check_dup_subtree();

        cout << "Duplicate subtrees are:\n";
        for (int i : res)
            cout << i << " ";
    }

    return 0;
}