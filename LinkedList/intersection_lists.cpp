#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1
 * Description:
    Given two lists sorted in increasing order, create a new list representing 
    the intersection of the two lists. The new list should be made with its own memory — 
    the original lists should not be changed.

    Examples:

    Input:
    L1 = 1->2->3->4->6
    L2 = 2->4->6->8
    Output: 2 4 6
    Explanation: 
    For the given first two linked list, 2, 4 and 6 are the elements in the intersection.

    Input:
    L1 = 10->20->40->50
    L2 = 15->40
    Output: 40
    
    Expected Time Complexity : O(n+m)
    Expected Auxilliary Space : O(n+m)
    Note: n,m are the size of the linked lists.

    Constraints:
    1 <= size of linked lists <= 5000
    1 <= Data in linked list nodes <= 1000
 * Resources:
 *  https://www.geeksforgeeks.org/intersection-of-two-sorted-linked-lists/
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
    Node(int data)
    {
        this->data = data;
        next = NULL;
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
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data << "\n";
    }

    /* Function to create list of a given size */
    Node *build_list(int size)
    {
        int data{0};
        si(data);
        Node *head = new Node(data);
        Node *tail = head;
        fo(i, 1, size)
        {
            si(data);
            tail->next = new Node(data);
            tail = tail->next;
        }
        return head;
    }
};

Node *find_intersections(Node *first, Node *second)
{
    Node *res_head{NULL}, *res_tail{NULL};
    while (first && second)
    {
        if (first->data == second->data)
        {
            Node *new_node = new Node(first->data);

            if (res_head == NULL)
                res_head = new_node;
            else
                res_tail->next = new_node;

            res_tail = new_node;

            first = first->next;
            second = second->next;
        }
        else if (first->data < second->data)
            first = first->next;
        else
            second = second->next;
    }

    return res_head;
}

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

        LinkedList first;
        first.head = first.build_list(n);

        cout << "First Linked List: \n";
        first.print();

        int m{0};
        si(m);

        LinkedList second;
        second.head = second.build_list(m);

        cout << "Second Linked List: \n";
        second.print();

        LinkedList result;
        result.head = find_intersections(first.head, second.head);

        cout << "Result Linked List: \n";
        result.print();
    }

    return 0;
}