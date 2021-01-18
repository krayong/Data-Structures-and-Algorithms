#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/
 * Description:
    Given a sorted doubly linked list of distinct nodes(no two nodes have the same data) 
    and a value x. Count triplets in the list that sum up to a given value x.

    Example: https://media.geeksforgeeks.org/wp-content/uploads/dll7.jpg
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

    int triplet_sum(Node *head, int x)
    {
        if (head == NULL) return 0;

        Node *tail = head;
        while (tail->next != NULL)
            tail = tail->next;

        int count = 0;

        for (Node *ptr = head; ptr->next != NULL; ptr = ptr->next) {
            Node *first = ptr->next;
            Node *last = tail;

            while (first != NULL && last != NULL && first != last && last->next != first)
            {
                if (first->data + last->data == x - ptr->data)
                {
                    ++count;

                    first = first->next;
                    last = last->prev;
                }
                else if (first->data + last->data < x - ptr->data)
                    first = first->next;
                else
                    last = last->prev;
            }
        }

        return count;
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

        int x{0};
        si(x);

        cout << "Triplets with sum " << x << " are: " << l.triplet_sum(l.head, x) << "\n";
    }

    return 0;
}