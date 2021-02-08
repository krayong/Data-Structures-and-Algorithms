#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
 * Description:
    Given an array arr[] denoting heights of N towers and a positive integer K, 
    modify the heights of each tower either by increasing or decreasing them by K only once. 
    Find out the minimum difference of the heights of shortest and longest modified towers.

    Input:
    K = 2, N = 4
    Arr[] = {1, 5, 8, 10}

    Output: 5

    Explanation: The array can be modified as {3, 3, 6, 8}. 
    The difference between the largest and the smallest is 8-3 = 5.

    Expected Time Complexity: O(N*logN)
    Expected Auxiliary Space: O(1)

 * Resources:
 *  https://www.geeksforgeeks.org/minimize-the-maximum-difference-between-the-heights/
 *  https://stackoverflow.com/questions/32233916/minimum-difference-between-heights-of-towers/
 * 
*************************************************************************************************************/

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define ss(s) getline(cin, s)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ps(s) cout << s << "\n";
#define fo(i, n) for (int i = 0; i < n; i++)
// #define fo(i, k, n) for (int i = k; k < n ? i < n : i >= n; k < n ? i++ : i--)
#define ll long long
#define deb(x) cout << #x << "=" << x << "\n"
#define pb push_back
#define mp make_pair
#define f first
#define s second
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
        int n{0}, k{0};
        si(n);
        si(k);
        int arr[n];
        fo(i, n) si(arr[i]);

        sort(arr, arr + n);
        int min_diff = arr[n - 1] - arr[0];
        int lo = arr[0] + k, hi = arr[n - 1] - k;
        fo(i, n - 1)
        {
            int min_height = min(lo, arr[i + 1] - k);
            int max_height = max(hi, arr[i] + k);
            if (min_height < 0) continue;
            min_diff = min(min_diff, max_height - min_height);
        }

        ps(min_diff);
    }

    return 0;
}