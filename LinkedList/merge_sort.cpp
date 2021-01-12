#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1
 * Description:
    Given Pointer/Reference to the head of the linked list, 
    the task is to Sort the given linked list using Merge Sort.
    Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

    Examples:

    Input:
    N = 5
    value[]  = {3,5,2,4,1}
    Output: 1 2 3 4 5
    Explanation: 
    After sorting the given linked list, the resultant matrix will be 1->2->3->4->5.

    Input:
    N = 3
    value[]  = {9,15,0}
    Output: 0 9 15
    Explanation: 
    After sorting the given linked list , resultant will be 0->9->15.
   
    Expected Time Complexity: O(N*Log(N))
    Expected Auxiliary Space: O(N)

    Constraints:
    1 <= T <= 100
    1 <= N <= 105
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

    Node *merge(Node *first, Node *second)
    {
        if (first == NULL)
            return second;
        if (second == NULL)
            return first;

        if (first->data < second->data)
        {
            first->next = merge(first->next, second);
            return first;
        }
        else
        {
            second->next = merge(first, second->next);
            return second;
        }
    }

    Node *merge_sort(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *slow{head}, *fast{head->next};
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *second_head = slow->next;
        slow->next = NULL;

        return merge(merge_sort(head), merge_sort(second_head));
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

        l.head = l.merge_sort(l.head);

        cout << "Sorted Linked List: \n";
        l.print();
    }

    return 0;
}