#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
 * Description:
    Given a binary tree and two node values your task is to find the minimum distance between them.

    Examples:

    Input:
        1
      /  \
     2    3
    a = 2, b = 3
    Output: 2
    Explanation: The tree formed is:
       1
     /   \ 
    2     3
    We need the distance between 2 and 3. Being at node 2, we need to take two steps ahead in order to reach node 3.
    The path followed will be: 2 -> 1 -> 3. Hence, the result is 2. 
    
    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(Height of the Tree).

    Constraints:
    1 <= Number of nodes <= 104
    1 <= Data of a node <= 105
 * Resources:
 *  https://www.geeksforgeeks.org/find-distance-between-two-nodes-of-a-binary-tree/
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

    bool check_if_exists(Node *root, int num)
    {
        if (root == NULL)
            return false;

        if (root->data == num || check_if_exists(root->left, num) || check_if_exists(root->right, num))
            return true;

        return false;
    }

    Node *find_lca(Node *root, int num1, bool &num1_found, int num2, bool &num2_found)
    {
        if (root == NULL)
            return NULL;

        if (root->data == num1)
        {
            num1_found = true;
            return root;
        }

        if (root->data == num2)
        {
            num2_found = true;
            return root;
        }

        auto lt = find_lca(root->left, num1, num1_found, num2, num2_found);
        auto rt = find_lca(root->right, num1, num1_found, num2, num2_found);

        if (lt && rt)
            return root;

        return (lt == NULL) ? rt : lt;
    }

    Node *find_lca(int num1, int num2)
    {
        bool num1_found = false, num2_found = false;

        Node *lca = find_lca(this->root, num1, num1_found, num2, num2_found);

        if (num1_found && num2_found || num1_found && check_if_exists(this->root, num2) || num2_found && check_if_exists(this->root, num1))
            return lca;

        return NULL;
    }

    int find_level(Node *root, int num)
    {
        if (root == NULL)
            return -1;

        if (root->data == num)
            return 0;

        int left_lvl = find_level(root->left, num) + 1;
        int right_lvl = find_level(root->right, num) + 1;

        if (left_lvl > 0)
            return left_lvl;
        else if (right_lvl > 0)
            return right_lvl;
        else
            return -1;
    }

    int find_dist(int num1, int num2)
    {
        Node *lca = find_lca(num1, num2);

        if (lca == NULL)
            return -1;

        int num1_dist = find_level(this->root, num1);
        int num2_dist = find_level(this->root, num2);

        int lca_dist = find_level(this->root, lca->data);
        
        if (num1_dist == -1 || num2_dist == -1)
            return -1;
        return (num1_dist + num2_dist - (2 * lca_dist));
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

        int num1, num2;
        si(num1);
        si(num2);

        cout << "Inorder traversal:\n";
        bt.print_in_order();

        cout << "Distance between " << num1 << " and " << num2 << " is: " << bt.find_dist(num1, num2);
    }

    return 0;
}