#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/minimum-swaps/1
 * Description:
    Given an array of n distinct elements, find the minimum number of swaps required to sort the array.

    Examples: 
    Input : {4, 3, 2, 1}
    Output : 2
    Explanation : Swap index 0 with 3 and 1 with 2 to form the sorted array {1, 2, 3, 4}.

    Input : {1, 5, 4, 3, 2}
    Output : 2
 * Resources:
 *  https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
 *  https://www.geeksforgeeks.org/minimum-number-of-swaps-required-to-sort-an-array-set-2/
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

int min_swaps(int arr[], int n)
{
    vpii arr_pos;
    fo(i, n) arr_pos.pb(mp(arr[i], i));

    sortall(arr_pos);

    int swaps{0};

    vector<bool> vis(n, false);

    fo(i, n)
    {
        if (vis[i] || arr_pos[i].se == i) continue; // already visited or is already at currect position

        int cycle_size{0}, next{i};
        while (!vis[next])
        {
            vis[next] = true;

            next = arr_pos[next].se;
            ++cycle_size;
        }

        if (cycle_size > 0) swaps += cycle_size - 1;
    }

    return swaps;
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

        int arr[n] = {0};
        fo(i, n) si(arr[i]);

        ps(min_swaps(arr, n));
    }

    return 0;
}