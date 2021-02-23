#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/
 * Description:
    Given weights and values of N items, we need to put these items in a knapsack of capacity W 
    to get the maximum total value in the knapsack.
    Note: Unlike 0/1 knapsack, you are allowed to break the item. 

    Examples:

    Input:
    N = 3, W = 50
    values[] = {60,100,120}
    weight[] = {10,20,30}
    Output: 240.00
    Explanation: Total maximum value of item we can have is 240.00 from the given capacity of sack. 

    Input:
    N = 2, W = 50
    values[] = {60,100}
    weight[] = {10,20}
    Output: 160.00
    Explanation: Total maximum value of item we can have is 160.00 from the given capacity of sack.

    Expected Time Complexity : O(NlogN)
    Expected Auxilliary Space: O(1)

    Constraints:
    1 <= N <= 100
    1 <= W <= 100
 * Resources:
 *  https://www.geeksforgeeks.org/fractional-knapsack-problem/
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

double fractional_knapsack(pii items[], int n, int w)
{
    sort(items, items + n, [](pii a, pii b) {
        return (static_cast<double>(a.fi) / a.se) > (static_cast<double>(b.fi) / b.se);
    });

    double val = 0.0;
    
    fo(i, 0, n)
    {
        if (items[i].se <= w)
        {
            val += items[i].fi;
            w -= items[i].se;
        }
        else
        {
            val += items[i].fi * (static_cast<double>(w) / items[i].se);
            break;
        }
    }

    return val;
}

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

        pii items[n];
        fo(i, 0, n) si(items[i].fi), si(items[i].se);

        int w;
        si(w);

        cout << "Maximum value we can obtain is: " << fractional_knapsack(items, n, w) << "\n";
    }

    return 0;
}