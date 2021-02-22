#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/find-median-bst-time-o1-space/
 * Description:
    Given a Binary Search Tree, find median of it.

    If no. of nodes are even: then median = ((n/2th node + (n+1)/2th node) /2
    If no. of nodes are odd : then median = (n+1)/2th node.
    
    Example:
    Given BST(with odd no. of nodes) is : 
                    6
                 /    \
                3      8
              /  \   /  \
             1    4 7    9

    Inorder of Given BST will be : 1, 3, 4, 6, 7, 8, 9
    So, here median will 6

    Given BST(with even no. of nodes) is :  
                    6
                 /    \
                3      8
              /  \    /  
             1    4  7    

    Inorder of Given BST will be : 1, 3, 4, 6, 7, 8
    So, here median will (4+6)/2 = 5
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

    int count_nodes()
    {
        int count = 0;
        if (this->root == NULL)
            return count;

        Node *curr = this->root, *prev = NULL;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                ++count;
                curr = curr->right;
            }
            else
            {
                prev = curr->left;
                while (prev->right != NULL && prev->right != curr)
                    prev = prev->right;

                if (prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    ++count;
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return count;
    }

    int median()
    {
        if (this->root == NULL)
            return 0;

        int num_nodes = count_nodes(), count = 0;

        Node *curr = this->root, *prev;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                ++count;
                if ((num_nodes % 2 != 0) && (count == (num_nodes + 1) / 2))
                    return curr->data;
                else if ((num_nodes % 2 == 0) && (count == (num_nodes / 2) + 1))
                    return (prev->data + curr->data) / 2;

                prev = curr;
                curr = curr->right;
            }
            else
            {
                Node *temp = curr->left;
                while (temp->right != NULL && temp->right != curr)
                    temp = temp->right;

                if (temp->right == NULL)
                {
                    temp->right = curr;
                    curr = curr->left;
                }
                else
                {
                    temp->right = NULL;
                    prev = temp;

                    ++count;
                    if ((num_nodes % 2 != 0) && (count == (num_nodes + 1) / 2))
                        return curr->data;
                    else if ((num_nodes % 2 == 0) && (count == (num_nodes / 2) + 1))
                        return (prev->data + curr->data) / 2;

                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        return INT_MAX;
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

        cout << "Median of bst nodes is: " << bst.median() << "\n";
    }

    return 0;
}