#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.spoj.com/problems/SUBSUMS/
 * Description:
    Given a sequence of N (1 ≤ N ≤ 34) numbers S1, ..., SN (-20,000,000 ≤ Si ≤ 20,000,000), 
    determine how many subsets of S (including the empty one) have a sum between A and B 
    (-500,000,000 ≤ A ≤ B ≤ 500,000,000), inclusive.

    Input
    The first line of standard input contains the three integers N, A, and B. 
    The following N lines contain S1 through SN, in order.

    Output
    Print a single integer to standard output representing the number of subsets 
    satisfying the above property. Note that the answer may overflow a 32-bit integer.

    Example:
    Input:
    3 -1 2
    1
    -2
    3
    Output:
    5
    Explanation:
    0 = 0 (the empty subset)
    1 = 1
    1 + (-2) = -1
    -2 + 3 = 1
    1 + (-2) + 3 = 2
 * Resources:
 *  https://www.geeksforgeeks.org/meet-in-the-middle/
 *  https://www.geeksforgeeks.org/subsets-sum-b/
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

void generate_subset(int start, int size, ll arr[], vl res)
{
    ll pow_size = pow(2, size);

    fo(counter, 0, pow_size)
    {
        int sum{0};
        fo(j, 0, size) if (counter & (1 << j)) sum += arr[j + start];
        res.pb(sum);
    }
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
        ll a{0}, b{0};
        si(n);
        sll(a);
        sll(b);

        ll arr[n] = {0};
        fo(i, 0, n) sll(arr[i]);

        vl s1, s2;
        generate_subset(0, n / 2, arr, s1);
        generate_subset(n / 2, n - (n / 2), arr, s2);

        sortall(s2);

        int ans{0};

        fo(i, 0, s1.size())
        {
            int low = lower_bound(all(s2), a - s1[i]) - s2.begin();
            int high = upper_bound(all(s2), b - s1[i]) - s2.begin();

            ans += (high - low);
        }

        pi(ans);
    }

    return 0;
}