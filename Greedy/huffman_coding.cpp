#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/huffman-encoding/1
 * Description:
    Given An array of Alphabets and their frequency. 
    Your task is to print all the given alphabets Huffman Encoding.
    
    Note: If two elements have same frequency, then the element which 
    if at first will be taken on left of Binary Tree and other one to right.

    Input:
    First line consists of test cases T. First line of every test case consists of string 
    of alphabets and second line consists of its frequencies.

    Output:
    Print the Huffman Codes of each alphabet in preorder form of Binary Tree.

    Constraints:
    1<=T<=100
    1<=|String length|<=26

    Example:
    Input:
    1
    abcdef
    5 9 12 13 16 45
    Output:
    0 100 101 1100 1101 111 

    Explanation:
    For the above test case, HuffmanCodes will be: 
    f: 0
    c: 100
    d: 101
    a: 1100
    b: 1101
    e: 111
 * Resources:
 *  https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
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

struct Node
{
    int freq;
    char data;
    Node *left, *right;

    Node(char data, int freq)
    {
        this->data = data;
        this->freq = freq;

        this->left = this->right = NULL;
    }
};

struct compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

void preorder(Node *root, string str, vector<pair<char, string>> &result)
{
    if (root == NULL)
        return;
    else if (root->data != '$')
        result.pb(mp(root->data, str));

    preorder(root->left, str + "0", result);
    preorder(root->right, str + "1", result);
}

vector<pair<char, string>> huffman_encoding(string alphabets, int freq[], int n)
{
    priority_queue<Node *, vector<Node *>, compare> pq;

    fo(i, 0, n) pq.push(new Node(alphabets[i], freq[i]));

    while (pq.size() > 1)
    {
        auto l = pq.top();
        pq.pop();

        auto r = pq.top();
        pq.pop();

        Node *new_top = new Node('$', l->freq + r->freq);
        new_top->left = l;
        new_top->right = r;

        pq.push(new_top);
    }

    vector<pair<char, string>> result;

    preorder(pq.top(), "", result);

    return result;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t;
    si(t);

    while (t--)
    {
        string alphabets;
        ss(alphabets);

        int n = alphabets.length();
        int freq[n];
        fo(i, 0, n) si(freq[i]);

        auto result = huffman_encoding(alphabets, freq, n);
        for (auto code : result)
            cout << code.fi << ": " << code.se << "\n";
    }

    return 0;
}