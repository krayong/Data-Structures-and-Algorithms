#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/brothers-from-different-root/
 * Description:
    Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x. 
    Count of all pairs from both the BSTs whose sum is equal to x.

    Examples:

    Input : 
        BST 1:    5        
                /   \      
               3     7      
              / \   / \    
             2  4  6   8   

        BST 2:    10        
                /   \      
               6     15      
              / \   /  \    
             3  8  11  18
        x = 16
    
    Output : 3

    Explanation:
    The pairs are: (5, 11), (6, 10) and (8, 8)

    Input:
    The function takes three arguments as input, first the reference pointer to the root(root1) of the BST1, 
    then reference pointer to the root(root2) of the BST2 and last the element X.
    There will be T test cases and for each test case the function will be called separately.

    Output:
    For each test cases print the required number of pairs on new line.

    Constraints:
    1<=T<=100
    1<=N<=103

    Example:
    Input:
    2
    7
    5 3 7 2 4 6 8
    7
    10 6 15 3 8 11 18
    16
    6
    10 20 30 40 5 1
    5
    25 35 10 15 5
    30
    Output:
    3
    2
 * Resources:
 *  https://www.geeksforgeeks.org/count-pairs-from-two-bsts-whose-sum-is-equal-to-a-given-value-x/
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

struct BinarySearchTree
{
    Node *root;
    int size;

    BinarySearchTree()
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

    void build_tree(int n)
    {
        this->size = n;

        fo(i, 0, n)
        {
            int temp;
            si(temp);
            this->root = insert(this->root, temp);
        }
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

    Node *insert(Node *root, int value)
    {
        if (root == NULL)
            return new Node(value);
        else if (root->data < value)
            root->right = insert(root->right, value);
        else
            root->left = insert(root->left, value);

        return root;
    }
};

bool search(Node *root, int val)
{
    if (root == NULL)
        return false;
    else if (root->data == val)
        return true;
    else if (root->data < val)
        return search(root->right, val);
    else
        return search(root->left, val);
}

int count_pairs(Node *root1, Node *root2, int x)
{
    if (root1 == NULL)
        return 0;

    int count = 0;
    if (search(root2, x - root1->data))
        count = 1;
    
    return count + count_pairs(root1->left, root2, x) + count_pairs(root1->right, root2, x);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t;
    si(t);

    while (t--)
    {
        int n1;
        si(n1);

        BinarySearchTree bst1;
        bst1.build_tree(n1);

        int n2;
        si(n2);

        BinarySearchTree bst2;
        bst2.build_tree(n2);

        int x;
        si(x);

        cout << "Inorder traversal of first tree:\n";
        bst1.print_in_order();

        cout << "Inorder traversal of second tree:\n";
        bst2.print_in_order();

        cout << "Number of pairs with sum " << x << " are " << count_pairs(bst1.root, bst2.root, x);
    }

    return 0;
}