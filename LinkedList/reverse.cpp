#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/reverse-a-linked-list/
 * Description:
    Given pointer to the head node of a linked list, the task is to reverse the linked list 
    (iteratively and recursively). We need to reverse the list by changing the links between nodes.
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
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << "\n";
    }

    /* Function to reverse a linked list iteratively */
    Node *reverse_iter(Node *head)
    {
        Node *current = head, *prev = NULL, *next = NULL;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;

            prev = current;
            current = next;
        }

        return prev;
    }

    /* Function to reverse a linked list recursively */
    Node *reverse_recur(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *rest = reverse_recur(head->next);

        head->next->next = head;
        head->next = NULL;

        return rest;
    }

    /* Function to push data in the linked list */
    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
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
        fo(i, 0, n)
        {
            int temp{0};
            si(temp);
            l.push(temp);
        }

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