#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/sort-k-sorted-doubly-linked-list/
 * Description:
    Given a doubly linked list containing n nodes, where each node is at most k away 
    from its target position in the list. The problem is to sort the given doubly linked list.
    For example, let us consider k is 2, a node at position 7 in the sorted doubly linked list, 
    can be at positions 5, 6, 7, 8, 9 in the given doubly linked list.

    Example: https://media.geeksforgeeks.org/wp-content/uploads/dll15.jpg
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

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

struct compare
{
    bool operator()(Node *p1, Node *p2)
    {
        return p1->data > p2->data;
    }
};

struct DoublyLinkedList
{
    Node *head;

    DoublyLinkedList()
    {
        head = NULL;
    }

    /* Function to print linked list */
    void print()
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            cout << temp->data << " <-> ";
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
            tail->next->prev = tail;
            tail = tail->next;
        }
        return head;
    }

    Node *sort_k_sorted(Node *head, int k)
    {
        if (head == NULL)
            return head;

        priority_queue<Node*, vector<Node*>, compare> pq;

        for (int i = 0; head != NULL && i <= k; head = head->next, i++)
            pq.push(head);

        Node *new_head = NULL, *temp = NULL;

        while (!pq.empty())
        {
            if (new_head == NULL)
            {
                new_head = pq.top();
                new_head->prev = NULL;
                temp = new_head;
            }
            else
            {
                temp->next = pq.top();
                pq.top()->prev = temp;
                temp = pq.top();
            }

            pq.pop();

            if (head != NULL)
            {
                pq.push(head);
                head = head->next;
            }
        }

        temp->next = NULL;

        return new_head;
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

        DoublyLinkedList l;
        l.head = l.build_list(n);

        cout << "Original Linked List: \n";
        l.print();

        int k{0};
        si(k);

        l.head = l.sort_k_sorted(l.head, k);

        cout << "Sorted Linked List: \n";
        l.print();
    }

    return 0;
}