#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
 * Description:
    Given two numbers represented by two linked lists of size N and M. 
    The task is to return a sum list. The sum list is a linked list 
    representation of the addition of two input numbers.

    Examples:

    Input: 
    N = 2
    valueN[] = {4,5}
    M = 3
    valueM[] = {3,4,5}
    Output: 
    3 9 0  
    Explanation: 
    For the given two linked list (4 5) and (3 4 5), after adding
    the two linked list resultant linked list will be (3 9 0).

    Input:
    N = 2
    valueN[] = {6,3}
    M = 1
    valueM[] = {7}
    Output: 
    7 0
    Explanation: 
    For the given two linked list (6 3) and (7), after adding the
    two linked list resultant linked list will be (7 0).
    
    Expected Time Complexity: O(N+M)
    Expected Auxiliary Space: O(Max(N,M))

    Constraints:
    1 <= N, M <= 5000
 * Resources:
 *  https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/
 *  https://www.geeksforgeeks.org/sum-of-two-linked-lists/
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
};

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

Node *add(Node *first, Node *second)
{
    first = reverse_iter(first);
    second = reverse_iter(second);

    Node *res_head{NULL}, *res_tail{NULL};
    int carry = 0;

    while (first || second)
    {
        int f = (first == NULL) ? 0 : first->data;
        int s = (second == NULL) ? 0 : second->data;

        int sum = f + s + carry;
        carry = sum / 10;
        sum = sum % 10;

        Node *new_node = new Node(sum);

        if (res_head == NULL)
            res_head = new_node;
        else
            res_tail->next = new_node;

        res_tail = new_node;

        if (first != NULL)
            first = first->next;

        if (second != NULL)
            second = second->next;
    }

    if (carry != 0)
    {
        res_tail->next = new Node(carry);
        res_tail = res_tail->next;
    }

    return reverse_iter(res_head);
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

        LinkedList first;
        first.head = first.build_list(n);

        cout << "First Linked List: \n";
        first.print();

        int m{0};
        si(m);

        LinkedList second;
        second.head = second.build_list(m);

        cout << "Second Linked List: \n";
        second.print();

        LinkedList result;
        result.head = add(first.head, second.head);

        cout << "Result Linked List: \n";
        result.print();
    }

    return 0;
}