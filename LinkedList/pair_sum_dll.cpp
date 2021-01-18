#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/
 * Description:
    Given a sorted doubly linked list of positive distinct elements, 
    the task is to find pairs in doubly linked list whose sum is 
    equal to given value x, without using any extra space

    Example:  
    Input : head -> 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
            x = 7
    Output: (6, 1), (5,2)

    Expected time complexity: O(n)
    Expected space complexity: O(1)
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

    void pair_sum(Node *head, int x)
    {
        Node *first = head, *last = head;
        while (last->next != NULL)
            last = last->next;

        bool found = false;

        while (first != NULL && last != NULL && first != last && last->next != first)
        {
            if (first->data + last->data == x)
            {
                found = true;
                cout << "(" << first->data << ", " << last->data << ")\n";
                first = first->next;
                last = last->prev;
            }
            else if (first->data + last->data < x)
                first = first->next;
            else
                last = last->prev;
        }

        if (!found)
            ps("NONE");
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

        cout << "Pairs with sum " << x << " are: \n";
        l.pair_sum(l.head, x);
    }

    return 0;
}