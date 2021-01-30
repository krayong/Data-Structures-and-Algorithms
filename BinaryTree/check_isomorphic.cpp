#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1
 * Description:
    Given two Binary Trees. Check whether they are Isomorphic or not.

    Examples:

    Input:
    T1:    1     T2:     1
          / \           / \
        2    3        3    2
       /             /
      4             4
    Output: No

    Input:
    T1:  1     T2:    1
        / \          / \
       2   3        3   2
      /                  \
     4                    4
    Output: Yes

    Note: 
    Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.
    For example, following two trees are isomorphic with following sub-trees flipped: 2 and 3, NULL and 6, 7 and 8.
    ISomorphicTrees

    Expected Time Complexity: O(min(M,N)) where M and N are the sizes of the two trees.
    Expected Auxiliary Space: O(min(H1,H2)) where H1 and H2 are the heights of the two trees.

    Constraints:
    1<=Number of nodes<=105
 * Resources:
 *  https://www.geeksforgeeks.org/tree-isomorphism-problem/
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

bool is_isomorphic(Node *n1, Node *n2)
{
    if (n1 == NULL && n2 == NULL) return true;

    if (n1 == NULL || n2 == NULL) return false;

    if (n1->data != n2->data) return false;

    return (is_isomorphic(n1->left, n2->left) && is_isomorphic(n1->right, n2->right)) ||
            (is_isomorphic(n1->left, n2->right) && is_isomorphic(n1->right, n2->left));
}

bool check_isomorphic(BinaryTree &bt1, BinaryTree &bt2)
{
    return is_isomorphic(bt1.root, bt2.root);
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

        BinaryTree bt1;
        bt1.build_level_order(n1);

        cout << "Inorder traversal of first tree:\n";
        bt1.print_in_order();

        int n2;
        si(n2);

        BinaryTree bt2;
        bt2.build_level_order(n2);

        cout << "Inorder traversal of second tree:\n";
        bt2.print_in_order();

        if (check_isomorphic(bt1, bt2))
            cout << "The trees are isomorphic\n";
        else
            cout << "The trees are not isomorphic\n";
    }

    return 0;
}