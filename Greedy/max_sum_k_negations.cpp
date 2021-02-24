#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1
 * Description:
    Given an array of integers of size N and a number K, you must modify array arr[] 
    exactly K number of times. Here modify array means in each operation you can replace 
    any array element either arr[i] by -arr[i] or -arr[i] by arr[i]. You need to perform 
    this operation in such a way that after K operations, the sum of the array must be maximum.

    Examples:

    Input:
    N = 5, K = 1
    arr[] = {1, 2, -3, 4, 5}
    Output: 15
    Explanation: We have k=1 so we can change -3 to 3 and sum all the elements to produce 15 as output.
    
    Input:
    N = 10, K = 5
    arr[] = {5, -2, 5, -4, 5, -12, 5, 5, 5, 20}
    Output: 68
    Explanation: 
    Here  we have k=5 so we turn -2, -4, -12 to 2, 4, and 12 respectively. Since we have
    performed 3 operations so k is now 2. To get maximum sum of array we can turn positive
    turned 2 into negative and then positive again so k is 0. Now sum is 5+5+4+5+12+5+5+5+20+2 = 68

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(1)

    Constraints:
    1 ≤ N ≤ 10^5
    -10^12 ≤ Ai ≤ 10^12
 * Resources:
 *  https://www.geeksforgeeks.org/maximize-array-sun-after-k-negation-operations/
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

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define randomize srand(chrono::high_resolution_clock::now().time_since_epoch().count())

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

ll max_sum_negations(ll arr[], int n, int k)
{
    fo(i, 0, k)
    {
        ll min_ele = LONG_LONG_MAX;
        int idx = -1;

        fo(j, 0, n)
        {
            if (arr[j] < min_ele)
            {
                min_ele = arr[j];
                idx = j;
            }
        }

        if (min_ele == 0)
            break;

        arr[idx] = -arr[idx];
    }

    ll sum = 0;
    fo(i, 0, n) sum += arr[i];
    return sum;
}

int main()
{
    fastio;
    randomize;

    int t;
    si(t);

    while (t--)
    {
        int n;
        si(n);

        ll arr[n];
        fo(i, 0, n) sll(arr[i]);

        int k;
        si(k);

        cout << "Maximum sum after " << k << " negations is: " << max_sum_negations(arr, n, k);
    }

    return 0;
}