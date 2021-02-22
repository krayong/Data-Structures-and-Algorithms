#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/
 * Description:
    Given a Binary search Tree that contains positive integer values greater then 0. 
    Find if the BST contains a dead or not. 
    Here Dead End means, we are not able to insert any element after that node.

    Examples:
    Input :   
               8
             /   \ 
           5      9
         /  \     
        2    7 
       /
      1     
          
    Output : Yes
    Explanation : Node "1" is the dead End because after that we cant insert any element.       

    Input :     
              8
            /   \ 
           7     10
         /      /   \
        2      9     13

    Output : Yes
    Explanation : We can't insert any element at node 9.  

    Input:
    The first line of the input contains an integer 'T' denoting the number of test cases. 
    Then 'T' test cases follow. Each test case consists of three lines. 
    First line of each test case contains an integer N denoting the no of nodes of the BST . 
    Second line of each test case consists of 'N' space separated integers denoting the 
    elements of the BST. These elements are inserted into BST in the given order.

    Output:
    The output for each test case will be 1 if the BST contains a dead end else 0.

    Constraints:
    1<=T<=100
    1<=N<=200
    
    Example:
    Input:
    2
    6
    8 5 9 7 2 1
    6
    8 7 10 9 13 2
    Output:
    1
    1
 * Resources:
 *  https://www.geeksforgeeks.org/check-whether-bst-contains-dead-end-not/
 *  https://www.geeksforgeeks.org/simple-recursive-solution-check-whether-bst-contains-dead-end/
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

    bool has_dead_end()
    {
        return has_dead_end(this->root);
    }

    bool has_dead_end(Node *root, int min = 1, int max = INT_MAX)
    {
        if (root == NULL)
            return false;
        else if (min == max)
            return true;
        else
            return has_dead_end(root->left, min, root->data - 1) || 
                    has_dead_end(root->right, root->data + 1, max);
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

        BinarySearchTree bst;
        bst.build_tree(n);

        cout << "Inorder traversal:\n";
        bst.print_in_order();

        if (bst.has_dead_end())
            cout << "Tree contains dead end\n";
        else
            cout << "Tree does not contain dead end\n";
    }

    return 0;
}