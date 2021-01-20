#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
 * Description:
    Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. 
    The left and right pointers in nodes are to be used as previous and next pointers 
    respectively in converted DLL. The order of nodes in DLL must be same as 
    Inorder of the given Binary Tree. The first node of Inorder traversal 
    (leftmost node in BT) must be the head node of the DLL.

    Examples:

    Input:
        1
      /  \
     3    2
    Output:
    3 1 2 
    2 1 3 
    Explanation: DLL would be 3<=>1<=>2

    Input:
            10
          /   \
        20    30
      /   \
     40   60
    Output:
    40 20 60 10 30 
    30 10 60 20 40
    Explanation:  DLL would be 
    40<=>20<=>60<=>10<=>30.

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(H).
    Note: H is the height of the tree and this space is used implicitly for recursion stack.

    Constraints:
    1 <= Number of nodes <= 1000
    1 <= Data of a node <= 1000
 * Resources:
 *  https://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
 *  https://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-2/
 *  https://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/
 *  https://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-4/
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

    void bt_to_dll_util(Node *root, Node *&head)
    {
        if (root == NULL)
            return;

        bt_to_dll_util(root->right, head);

        root->right = head;

        if (head != NULL)
            head->left = root;

        head = root;

        bt_to_dll_util(root->left, head);
    }

    Node *bt_to_dll()
    {
        Node *head = NULL;
        bt_to_dll_util(this->root, head);
        return head;
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

        Node *head = bt.bt_to_dll();

        cout << "Double linked list:\n";
        Node *prev = NULL;
        while (head != NULL)
        {
            cout << head->data << " ";
            prev = head;
            head = head->right;
        }
        cout << "\n";
        while(prev != NULL)
        {
            cout << prev->data << " ";
            prev = prev->left;
        }
        cout << "\n";
    }

    return 0;
}