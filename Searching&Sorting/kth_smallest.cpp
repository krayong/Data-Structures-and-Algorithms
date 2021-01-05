#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/kth-smallest-number-again-2/description/
 * Description:
    Dexter was good in finding the K th smallest number from a set of numbers. 
    He thought he could solve any problem related to K th smallest number. 
    His friend Pipi challenged him with a problem.
    He gave him various ranges of number, these numbers were arranged in increasing order
    (only distinct numbers to be taken into account). 
    Now he asked him to find the K th smallest number in the sequence, again and again.

    Input Format
    The first line contains T, the number of test cases.
    For each test case, there will be two integers N and Q.
    Then N lines follow each line containing two integers A and B (denoting the range A-B)
    Then Q lines follow each line containing a non-negative integer K .

    Output Format
    For each query output the K th smallest number.

    Constraints
    1 <= T <= 100
    1 <= N <= 100
    1 <= Q <= 1000
    -10^18 <= A <= B <= 10^18
    K >= 1

    N.B. If Kth smallest number is not present in the series, print -1
 * Resources:
 *  https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/kth-smallest-number-again-2/editorial/
 *  https://www.geeksforgeeks.org/find-k-th-smallest-element-in-given-n-ranges/
 * 
*************************************************************************************************************/

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define ss(s) getline(cin, s)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ps(s) cout << s << "\n"
#define fo(i, n) for (int i = 0; i < n; i++)
// #define fo(i, k, n) for (int i = k; k < n ? i < n : i >= n; k < n ? i++ : i--)
#define ll long long
#define deb(x) cout << #x << "=" << x << "\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
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

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t{0};
    si(t);

    while (t--)
    {
        int n{0}, q{0};
        si(n);
        si(q);

        vpll ranges;
        fo(i, n)
        {
            ll a, b;
            sll(a);
            sll(b);
            ranges.pb(mp(a, b));
        }

        sortall(ranges);

        vpll temp_ranges;
        temp_ranges.pb(ranges[0]);

        for (int i{1}; i < n; i++)
            if (ranges[i].fi > temp_ranges.back().se)
                temp_ranges.pb(ranges[i]);
            else
                temp_ranges.back().se = max(ranges[i].se, temp_ranges.back().se);

        ranges = temp_ranges;
        n = ranges.size();

        while (q--)
        {
            int k{0};
            si(k);

            int i{0};
            for (; i < n; i++)
                if (k <= (ranges[i].se - ranges[i].fi + 1))
                    break;
                else
                    k -= (ranges[i].se - ranges[i].fi + 1);

            if (k > 0)
                pi(-1);
            else
                pi(ranges[i].fi + k - 1);
        }
    }

    return 0;
}