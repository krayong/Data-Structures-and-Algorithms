#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                           Kadane's Algorithm   
 * Link : https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
 * Description:
    Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

    Input:
    The first line of input contains an integer T denoting the number of test cases. 
    The description of T test cases follows. 
    The first line of each test case contains a single integer N denoting the size of array. 
    The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

    Output:
    Print the maximum sum of the contiguous sub-array in a separate line for each test case.
 * Resources:
    https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
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
        int n{0};
        si(n);
        int arr[n];
        fo(i, n) si(arr[i]);

        int max_so_far{arr[0]}, curr_max{arr[0]};
        fo(i, n) {
            if (i == 0) continue;
            curr_max = max(arr[i], curr_max + arr[i]);
            max_so_far = max(max_so_far, curr_max);
        }
        
        ps(max_so_far);
    }

    return 0;
}