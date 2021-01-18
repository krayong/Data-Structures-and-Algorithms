#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
 * Description:
    Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
    (i) a next pointer to the next node,
    (ii) a bottom pointer to a linked list where this node is head.
    Each of the sub-linked-list is in sorted order.
    Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
    Note: The flattened list will be printed using the bottom pointer instead of next pointer.

    Examples:

    Input:
    5 -> 10 -> 19 -> 28
    |     |     |     | 
    7    20    22    35
    |           |     | 
    8          50    40
    |                 | 
    30               45
    Output:  
    5->7->8->10->19->20->22->28->30->35->40->45->50

    Input: 
    5 -> 10 -> 19 -> 28
    |           |    
    7          22   
    |           |    
    8          50 
    |                           
    30              

    Output: 5->7->8->10->19->20->22->30->50

    Note: | represents the bottom pointer.
    
    Expected Time Complexity: O(N*M)
    Expected Auxiliary Space: O(1)

    Constraints:
    0 <= N <= 50
    1 <= Mi <= 20
    1 <= Element of linked list <= 103
 * Resources:
 *  https://www.geeksforgeeks.org/flattening-a-linked-list/
 *  https://www.geeksforgeeks.org/flattening-a-linked-list-set-2/
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

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        bottom = NULL;
    }
};

struct LinkedList
{
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    /* Function to print linked list */
    void print()
    {
        Node *next_temp = head;
        while (next_temp != NULL)
        {
            cout << next_temp->data << "-";
            Node *bottom_temp = next_temp->bottom;
            while (bottom_temp->bottom != NULL)
            {
                cout << bottom_temp->data << "-";
                bottom_temp = bottom_temp->bottom;
            }
            cout << bottom_temp->data << "\n|\n";
            next_temp = next_temp->next;
        }
        cout << "\n";
    }

    /* Function to print flattened linked list */
    void print_flatten()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->bottom;
        }
        cout << "\n";
    }

    /* Function to merge two linked lists */
    Node *merge(Node *a, Node *b)
    {
        if (a == NULL)
            return b;
        else if (b == NULL)
            return a;

        Node *result = NULL;

        if (a->data < b->data)
        {
            result = a;
            result->bottom = merge(a->bottom, b);
        }
        else
        {
            result = b;
            result->bottom = merge(a, b->bottom);
        }

        result->next = NULL;
        return result;
    }

    /* Function to flatten a linked list */
    Node *flatten(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        return merge(head, flatten(head->next));
    }

    /* Function to build the linked list */
    Node *build_list(int n)
    {
        int sizes[n] = {0};
        fo(i, 0, n) si(sizes[i]);

        Node *head = NULL, *pre = NULL, *curr = NULL;
        fo(i, 0, n)
        {
            int temp{0};
            si(temp);

            Node *new_node = new Node(temp);
            if (head == NULL)
            {
                head = pre = curr = new_node;
            }
            else
            {
                pre->next = new_node;
                pre = pre->next;
                curr = pre;
            }

            fo(j, 1, sizes[i])
            {
                si(temp);
                new_node = new Node(temp);

                curr->bottom = new_node;
                curr = curr->bottom;
            }
        }

        return head;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t{0};
    si(t);

    while (t--)
    {
        int n{0};
        si(n);

        LinkedList l;
        l.head = l.build_list(n);

        cout << "Original Linked List: \n";
        l.print();

        cout << "Flattened Linked List: \n";
        l.head = l.flatten(l.head);
        l.print_flatten();
    }

    return 0;
}