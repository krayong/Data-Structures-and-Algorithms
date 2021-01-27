#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree/0
 * Description:
    Given two n-ary tree's the task is to check if they are mirror of each other or not.

    Input:
        1                     1
      /  \                  /  \
     2    3                3    2

    Output: 1
        1                     1
      /  \                  /  \
     2    3                2    3

    Output: 0

    Input:
    The first line of input contains an integer T denoting the no of test cases. 
    Then T test cases follow. The first line of each test case contains two space 
    separated values n and e denoting the no of nodes and edges respectively. 
    Then in the next line two lines are 2*e space separated values 
    u,v denoting an edge from u to v for the both trees .

    Output:
    For each test case in a new line print 1 if both the trees are mirrors of each other else print 0.

    Constraints:
    1<=T<=20
    1<=n<=15
    1<=e<=20

    Example:
    Input:
    2
    3 2
    1 2 1 3
    1 3 1 2
    3 2
    1 2 1 3
    1 2 1 3
    Output:
    1
    0
 * Resources:
 *  https://www.geeksforgeeks.org/check-mirror-n-ary-tree/
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

bool check_mirror(vector<stack<int>> &tree1, vector<queue<int>> &tree2)
{
    fo(i, 1, tree1.size()) // nodes are from 1 to n
    {
        stack<int> &s = tree1[i];
        queue<int> &q = tree2[i];

        while (!s.empty() && !q.empty())
        {
            if (s.top() != q.front())
                return false;

            s.pop();
            q.pop();
        }

        if (!s.empty() || !q.empty())
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t;
    si(t);

    while (t--)
    {
        int n, e;
        si(n);
        si(e);

        vector<stack<int>> tree1(n + 1);
        fo(i, 0, e)
        {
            int l, r;
            si(l);
            si(r);

            tree1[l].push(r);
        }

        vector<queue<int>> tree2(n + 1);
        fo(i, 0, e)
        {
            int l, r;
            si(l);
            si(r);

            tree2[l].push(r);
        }

        if (check_mirror(tree1, tree2))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}