#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1
 * Description:
    Sort the given Linked List using quicksort, which takes O(n^2) time in worst case 
    and O(nLogn) in average and best cases, otherwise you may get TLE.

    Example:
    Input:
    2
    3
    1 6 2
    4
    1 9 3 8

    Output:
    1 2 6
    1 3 8 9

    Explanation:
    Testcase 1: After sorting the nodes, we have 1, 2 and 6.
    Testcase 2: After sorting the nodes, we have 1, 3, 8 and 9.

    Constraints:
    1<=T<=100
    1<=N<=200
 * Resources:
 *  https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
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

    Node *partition(Node *head, Node *tail) {
        Node *prev = head, *curr = head->next, *pivot = head;

        while (curr != tail->next) {
            if (curr->data < pivot->data) {
                swap(prev->next->data, curr->data);
                prev = prev->next;
            }
            curr = curr->next;
        }

        swap(prev->data, pivot->data);

        return prev;
    }

    void quick_sort_rec(Node *head, Node *tail) {
        if (head == NULL || tail == NULL || head == tail) return;

        Node *pivot = partition(head, tail);

        quick_sort_rec(head, pivot);
        quick_sort_rec(pivot->next, tail);
    }

    Node *quick_sort(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *tail = head;
        while (tail->next != NULL) tail = tail->next;

        quick_sort_rec(head, tail);

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

        l.head = l.quick_sort(l.head);

        cout << "Sorted Linked List: \n";
        l.print();
    }

    return 0;
}