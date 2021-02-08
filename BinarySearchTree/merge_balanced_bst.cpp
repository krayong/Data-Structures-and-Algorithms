#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/
 * Description:
    You are given two balanced binary search trees e.g., AVL or Red Black Tree. 
    Write a function that merges the two given balanced BSTs into a balanced binary search tree. 
    Let there be m elements in first tree and n elements in the other tree. 
    Your merge function should take O(m+n) time.
    In the following solutions, it is assumed that sizes of trees are also given as input. 
    If the size is not given, then we can get the size by traversing the tree 
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

    void create_inorder(Node *root, vector<int> &inorder)
    {
        if (root != NULL)
        {
            create_inorder(root->left, inorder);
            inorder.pb(root->data);
            create_inorder(root->right, inorder);
        }
    }

    vi merge_vectors(vi &inorder1, vi &inorder2)
    {
        vi inorder;

        int i = 0, j = 0;
        
        while (i < inorder1.size() && j < inorder2.size())
        {
            if (inorder1[i] < inorder2[j])
                inorder.pb(inorder1[i++]);
            else
                inorder.pb(inorder2[j++]);
        }

        while (i < inorder1.size())
            inorder.pb(inorder1[i++]);

        while (j < inorder2.size())
            inorder.pb(inorder2[j++]);

        return inorder;
    }

    Node *convert_to_balanced_tree(vi &inorder, int lo, int hi)
    {
        if (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            Node *root = new Node(inorder[mid]);

            root->left = convert_to_balanced_tree(inorder, lo, mid - 1);
            root->right = convert_to_balanced_tree(inorder, mid + 1, hi);

            return root;
        }
        else
            return NULL;
    }

    void create_by_merge(BinarySearchTree &bst1, BinarySearchTree &bst2)
    {
        vi inorder1, inorder2;
        create_inorder(bst1.root, inorder1);
        create_inorder(bst2.root, inorder2);

        vi inorder = merge_vectors(inorder1, inorder2);

        this->root = convert_to_balanced_tree(inorder, 0, inorder.size() - 1);
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
        int m;
        si(m);

        BinarySearchTree bst1;
        bst1.build_tree(m);

        int n;
        si(n);

        BinarySearchTree bst2;
        bst2.build_tree(n);

        cout << "Inorder traversal of first binary search tree:\n";
        bst1.print_in_order();

        cout << "Inorder traversal of second binary search tree:\n";
        bst2.print_in_order();

        BinarySearchTree bst;
        bst.create_by_merge(bst1, bst2);

        cout << "Inorder traversal of merged binary search trees:\n";
        bst.print_in_order();
    }

    return 0;
}