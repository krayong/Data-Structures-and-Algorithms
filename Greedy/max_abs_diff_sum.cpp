#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/swap-and-maximize/0
 * Description:
    Given an array of n elements. Consider array as circular array i.e element after an 
    is a1. The task is to find maximum sum of the difference between consecutive elements 
    with rearrangement of array element allowed i.e after rearrangement of element find 
    |a1 – a2| + |a2 – a3| + …… + |an – 1– an| + |an – a1|.

    Input:
    The first line of input contains an integer T denoting the number of test cases. 
    Each test case contains the number of elements in the array a[] as n and 
    next line contains space separated n elements in the array a[].

    Output:
    Print an integer which denotes the maximized sum.

    Constraints:
    1<=T<=100
    1<=n<=10000
    1<=a[i]<=100000

    Example:
    Input:
    2
    4
    4 2 1 8
    3
    10 12 15
    Output:
    18
    10
 * Resources:
 *  https://www.geeksforgeeks.org/maximize-sum-consecutive-differences-circular-array/
 *  https://www.geeksforgeeks.org/maximum-sum-absolute-difference-array/
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

        int arr[n];
        fo(i, 0, n) si(arr[i]);

        sort(arr, arr + n);

        vi v;
        fo(i, 0, n / 2)
            v.pb(arr[i]),
            v.pb(arr[n - i - 1]);

        if (n % 2 != 0)
            v.pb(arr[n / 2]);

        int sum = 0;
        fo(i, 0, n - 1)
            sum += abs(v[i + 1] - v[i]);
        sum += abs(v[n - 1] - v[0]);

        cout << "Maximum sum is: " << sum << "\n";
    }

    return 0;
}