#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.codechef.com/FEB21C/problems/FROGS
 * Description:
    There are N frogs (numbered 1 through N) in a line. For each valid i, 
    the i-th frog is initially at the position i, it has weight Wi, 
    and whenever you hit its back, it jumps a distance Li to the right, 
    i.e. its position increases by Li. The weights of the frogs are pairwise distinct.

    You can hit the back of each frog any number of times 
    (possibly zero, not necessarily the same for all frogs) in any order. 
    The frogs do not intefere with each other, so there can be any 
    number of frogs at the same time at each position.

    Your task is to sort the frogs in the increasing order of weight 
    using the smallest possible number of hits. In other words, 
    after all the hits are performed, then for each pair of frogs (i,j) such that Wi<Wj, 
    the position of the i-th frog should be strictly smaller than the position of the j-th frog. 
    Find the smallest number of hits needed to achieve such a state.

    Input:
    The first line of the input contains a single integer T denoting the number of test cases. 
    The description of T test cases follows.
    The first line of each test case contains a single integer N.
    The second line contains N space-separated integers W1,W2,…,WN.
    The third line contains N space-separated integers L1,L2,…,LN.

    Output:
    For each test case, print a single line containing one integer ― 
    the smallest number of times you need to hit the backs of the frogs.

    Constraints:
    1≤T≤2⋅10^4
    2≤N≤4
    1≤Wi≤N for each valid i
    1≤Li≤5 for each valid i
    no two frogs have the same weight

    Example Input:
    3
    3
    3 1 2
    1 4 5
    3
    3 2 1
    1 1 1
    4
    2 1 4 3
    4 1 2 4

    Example Output:
    3
    6
    5

    Explanation:
    Example case 1: We can hit the back of the first frog three times.
    Example case 2: We can hit the back of the first frog four times, 
    then hit the back of the second frog two times.
 * Resources:
 *  https://www.codechef.com/FEB21C/status/FROGS?sort_by=All&sorting_order=asc&language=44&status=15&handle=&Submit=GO
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

struct frog
{
    int pos;
    int weight;
    int jump_distance;
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t;
    si(t);

    while (t--)
    {
        int n;
        si(n);

        frog frogs[n];

        fo(i, 0, n)
        {
            si(frogs[i].weight);
            frogs[i].pos = i + 1;
        }

        fo(i, 0, n) si(frogs[i].jump_distance);

        sort(frogs, frogs + n, [](frog a, frog b) {
            return a.weight < b.weight;
        });

        int min_jumps = 0;
        fo(i, 1, n)
        {
            while (frogs[i].pos <= frogs[i - 1].pos)
            {
                frogs[i].pos += frogs[i].jump_distance;
                ++min_jumps;
            }
        }

        cout << min_jumps << "\n";
    }

    return 0;
}