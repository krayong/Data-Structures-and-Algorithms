#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
 * Description:
    Given arrival and departure times of all trains that reach a railway station. Find the 
    minimum number of platforms required for the railway station so that no train is kept 
    waiting. Consider that all the trains arrive on the same day and leave on the same day. 
    Arrival and departure time can never be the same for a train but we can have arrival time 
    of one train equal to departure time of the other. At any given instance of time, same 
    platform can not be used for both departure of a train and arrival of another train. 
    In such cases, we need different platforms.

    Examples:

    Input: N = 6 
    arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
    dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
    Output: 3
    Explanation: Minimum 3 platforms are required to safely arrive and depart all trains.

    Input: N = 3
    arr[] = {0900, 1100, 1235}
    dep[] = {1000, 1200, 1240}
    Output: 1
    Explanation: Only 1 platform is required to safely manage the arrival and departure of all trains. 

    Expected Time Complexity: O(nLogn)
    Expected Auxiliary Space: O(n)

    Constraints:
    1 <= N <= 1000
    1 <= A[i] < D[i] <= 2359
 * Resources:
 *  https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
 *  https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station-set-2-map-based-approach/
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

int num_platforms(pii timings[], int n)
{
    int platform[2400] = {0};

    fo(i, 0, n)
    {
        platform[timings[i].fi]++;
        platform[timings[i].se + 1]--;
    }

    int num_plats = 1;
    fo(i, 1, 2400)
    {
        platform[i] += platform[i - 1];
        num_plats = max(num_plats, platform[i]);
    }

    return num_plats;
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

        pii timings[n];
        fo(i, 0, n) si(timings[i].fi), si(timings[i].se);

        cout << "Number of platforms required are: " << num_platforms(timings, n) << "\n";
    }

    return 0;
}