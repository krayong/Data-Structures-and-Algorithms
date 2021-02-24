#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1
 * Description:
    Given an array A of N integers. Your task is to write a program to find 
    the maximum value of ∑arr[i]*i, where i = 0, 1, 2,…., n – 1.
    You are allowed to rearrange the elements of the array.
    Note: Since output could be large, hence module 10^9+7 and then print answer.

    Examples:

    Input : arr[] = {5, 3, 2, 4, 1}
    Output : 40
    Explanation:
    If we arrange the array as 1 2 3 4 5 then we can see that the minimum index 
    will multiply with minimum number and maximum index will multiply with 
    maximum number. So 1*0+2*1+3*2+4*3+5*4=0+2+6+12+20 = 40 mod(10^9+7) = 40

    Input : arr[] = {1, 2, 3}
    Output : 8

    Expected Time Complexity: O(nlog(n)).
    Expected Auxiliary Space: O(1).

    Constraints:
    1 ≤ N ≤ 10^7
    1 ≤ Ai ≤ N
 * Resources:
 *  https://www.geeksforgeeks.org/maximize-sum-arrii/
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

ll max_sum(ll arr[], int n)
{
    sort(arr, arr + n);

    ll sum = 0;
    fo(i, 0, n)
    {
        if (i == 0 || arr[i] == 0)
            continue;

        sum += ((arr[i] * i) % 1000000007);
        sum %= 1000000007;
    }

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

        cout << "Max sum of arr[i] * i for i from 0 to "
             << n << " is " << max_sum(arr, n);
    }

    return 0;
}