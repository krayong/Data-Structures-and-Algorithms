#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1
 * Description:
    You are given an array A[] of size N. Find the total count of sub-arrays having their sum equal to 0.
 * Resources:
 *  https://www.geeksforgeeks.org/print-all-subarrays-with-0-sum/
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
        int n{0};
        si(n);

        int arr[n] = {0};
        fo(i, n) si(arr[i]);

        unordered_map<int, vi> um;
        vpii indices;

        int sum{0};
        fo(i, n)
        {
            sum += arr[i];

            if (sum == 0)
                indices.pb(mp(0, i));

            if (present(um, sum))
            {
                vi nums = um.at(sum); // nums contains those indices where total sum was same as current sum
                for (int num : nums)  // so sum between (any num in nums, i] = 0
                    indices.pb(mp(num + 1, i));
            }

            um[sum].pb(i);
        }

        int count = indices.size();
        pi(count);
        for (pii index : indices)
            cout << index.fi << " " << index.se << "\n";
    }

    return 0;
}