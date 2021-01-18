#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/rotate-doubly-linked-list-n-nodes/
 * Description:
    Given a doubly linked list, rotate the linked list counter-clockwise by N nodes. 
    Here N is a given positive integer and is smaller than the count of nodes in linked list.

    Examples:

    Input : a  b  c  d  e   N = 2
    Output : c  d  e  a  b 

    Input : a  b  c  d  e  f  g  h   N = 4
    Output : e  f  g  h  a  b  c  d 
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

    Node *rotate(Node *head, int k)
    {
        if (head == NULL)
            return head;

        Node *curr = head;
        for (int i = 1; curr != NULL && i < k; i++)
            curr = curr->next;

        Node *last = curr;
        while (last->next != NULL)
            last = last->next;

        last->next = head;
        head->prev = last;

        Node *new_head = curr->next;

        curr->next->prev = NULL;
        curr->next = NULL;

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

        l.head = l.rotate(l.head, k);

        cout << "Rotated Linked List: \n";
        l.print();
    }

    return 0;
}