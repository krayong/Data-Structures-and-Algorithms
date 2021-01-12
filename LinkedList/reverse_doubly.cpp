#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
 * Description:
    Given a doubly linked list of n elements. The task is to reverse the doubly linked list.

    Examples:

    Input:
    LinkedList: 3 <--> 4 <--> 5
    Output: 5 4 3
    Example 2:

    Input:
    LinkedList: 75 <--> 122 <--> 59 <--> 196
    Output: 196 59 122 75
    
    Expected Time Complexity: O(n).
    Expected Auxiliary Space: O(1).

    Constraints:
    1 <= number of nodes <= 103
    0 <= value of nodes <= 103
 * Resources:
 *  https://www.geeksforgeeks.org/reverse-a-doubly-linked-list/
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

    /* Function to reverse a linked list iteratively */
    Node *reverse_iter(Node *head)
    {
        Node *current = head, *temp = NULL;

        while (current != NULL)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        return temp->prev;
    }

    /* Function to reverse a linked list recursively */
    Node *reverse_recur(Node *head)
    {
        if (head == NULL)
            return head;

        Node *temp = head->next;
        head->next = head->prev;
        head->prev = temp;

        if (head->prev == NULL)
            return head;
        else
            return reverse_recur(head->prev);
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

        cout << "Reversed Linked List: \n";
        l.head = l.reverse_iter(l.head);
        l.print();

        cout << "Original Linked List: \n";
        l.head = l.reverse_recur(l.head);
        l.print();
    }

    return 0;
}