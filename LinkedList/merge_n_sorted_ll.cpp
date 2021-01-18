#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
 * Description:
    Given N sorted linked lists of different sizes. 
    The task is to merge them in such a way that after merging they will be a single sorted linked list.

    Examples:

    Input:
    N = 4
    value = {{1,2,3},{4 5},{5 6},{7,8}}
    Output: 1 2 3 4 5 5 6 7 8
    Explanation:
    The test case has 4 sorted linked list of size 3, 2, 2, 2
    1st    list     1 -> 2-> 3
    2nd   list      4->5
    3rd    list      5->6
    4th    list      7->8
    The merged list will be: 1->2->3->4->5->5->6->7->8.

    Input:
    N = 3
    value = {{1,3},{4,5,6},{8}}
    Output: 1 3 4 5 6 8
    Explanation:
    The test case has 3 sorted linked list of size 2, 3, 1.
    1st list 1 -> 3
    2nd list 4 -> 5 -> 6
    3rd list 8
    The merged list will be: 1->3->4->5->6->8.
    
    Expected Time Complexity: O(nk Logn)
    Expected Auxiliary Space: O(n)
    Note: k is the maximum size of all the n link list

    Constraints
    1 <= n <= 103
 * Resources:
 *  https://www.geeksforgeeks.org/merge-k-sorted-linked-lists/
 *  https://www.geeksforgeeks.org/merge-k-sorted-linked-lists-set-2-using-min-heap/
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

struct compare
{
    bool operator()(Node *p1, Node *p2)
    {
        return p1->data > p2->data;
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
};

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

Node *merge_n_sorted(Node *arr[], int n)
{
    priority_queue<Node *, vector<Node *>, compare> pq;
    fo(i, 0, n)
    {
        if (arr[i] != NULL)
            pq.push(arr[i]);
    }

    if (pq.empty()) return NULL;

    Node *head = NULL, *tail = NULL;
    while (!pq.empty())
    {
        Node *temp = pq.top();
        pq.pop();

        if (head == NULL)
            head = tail = temp;
        else
        {
            tail->next = temp;
            tail = tail->next;
        }

        if (temp->next != NULL)
            pq.push(temp->next);
    }

    return head;
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

        Node *arr[n];
        fo(i, 0, n)
        {
            int k{0};
            si(k);

            arr[i] = build_list(k);
        }

        fo(i, 0, n)
        {
            Node *temp = arr[i];
            while (temp->next != NULL) {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << temp->data << "\n";
        }

        LinkedList l;
        l.head = merge_n_sorted(arr, n);

        cout << "Sorted Linked List: \n";
        l.print();
    }

    return 0;
}