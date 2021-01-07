#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1
 * Description:
    Given a number n. The task is to find the smallest number 
    whose factorial contains at least n trailing zeroes.

    Examples:

    Input: n = 1
    Output: 5
    Explanation : 5! = 120 which has at least 1 trailing 0.

    Input: n = 6
    Output: 25
    Explanation : 25! has at least 6 trailing 0.

    Expected Time Complexity: O(log2 N * log5 N).
    Expected Auxiliary Space: O(1).

    Constraints:
    1 <= n <= 104
 * Resources:
 *  https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
 *  https://www.geeksforgeeks.org/smallest-number-least-n-trailing-zeroes-factorial/
 * 
*************************************************************************************************************/

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define ss(s) getline(cin, s)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ps(s) cout << s << "\n"
#define fo(i, k, n) for (int i = k; i < n; i++)
#define rof(i, k, n) for (int i = k; i >= n; i--)
#define ll long long
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

bool check(int num, int req_trailing_zeros)
{
    int found_trailing_zeros{0};
    for (int i{5}; num / i >= 1; i *= 5)
        found_trailing_zeros += num / i;

    return (found_trailing_zeros >= req_trailing_zeros);
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

        int lo{0}, hi{n * 5};
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(mid, n))
                hi = mid;
            else
                lo = mid + 1;
        }

        pi(lo);
    }

    return 0;
}