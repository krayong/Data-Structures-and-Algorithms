#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
 * Description:
    Given a linked list of N nodes. The task is to check if the the linked list has a loop. 
    Linked list can contain self loop.

    Examples:

    Input:
    N = 3
    value[] = {1,3,4}
    x = 2
    Output: True
    Explanation: In above test case N = 3. The linked list with nodes N = 3 is given. 
                 Then value of x=2 is given which means last node is connected with xth
                 node of linked list. Therefore, there exists a loop.

    Input:
    N = 4
    value[] = {1,8,3,4}
    x = 0
    Output: False
    Explanation: For N = 4 ,x = 0 means then lastNode->next = NULL, then
                 the Linked list does not contains any loop.

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(1)

    Constraints:
    1 <= N <= 104
    1 <= Data on Node <= 103
 * Resources:
 *  https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
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

    /* Function to print linked list having loop */
    void print(int n)
    {
        ++n; // to print start of the loop
        struct Node *temp = head;
        while (n-- && temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << "\n";
    }

    /* Function to check if linked list has a loop */
    bool detect_loop(Node *head)
    {
        if (head == NULL) return false;

        Node *hare = head, *tortoise = head;
        while (tortoise != NULL && hare != NULL && hare->next != NULL)
        {
            hare = hare->next->next;
            tortoise = tortoise->next;
            if (hare == tortoise) return true;
        }
        return false;
    }

    /* Function to create loop at position x */
    void create_loop(int x)
    {
        if (x == 0) return;

        Node *temp = head;
        while (--x != 0)
            temp = temp->next;

        Node *node_at_x = temp;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = node_at_x;
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

        int x{0};
        si(x);

        l.create_loop(x);

        // Printing list is not possible normally as it has infinite length because of the loop
        cout << "Original Linked List: \n";
        // l.print();
        l.print(n);

        if (l.detect_loop(l.head))
            cout << "The linked list has loop\n";
        else
            cout << "The linked list has no loop\n";
    }

    return 0;
}