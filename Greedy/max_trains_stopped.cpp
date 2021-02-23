#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/
 * Description:
    We are given n-platform and two main running railway track for both direction. 
    Trains which needs to stop at your station must occupy one platform for their stoppage 
    and the trains which need not to stop at your station will run away through 
    either of main track without stopping. Now, each train has three value first 
    arrival time, second departure time and third required platform number. 
    We are given m such trains you have to tell maximum number of train for which 
    you can provide stoppage at your station.

    Examples:

    Input : n = 3, m = 6 
    Train no.|  Arrival Time |Dept. Time | Platform No.
        1    |   10:00       |  10:30    |    1
        2    |   10:10       |  10:30    |    1
        3    |   10:00       |  10:20    |    2
        4    |   10:30       |  12:30    |    2
        5    |   12:00       |  12:30    |    3
        6    |   09:00       |  10:05    |    1
    Output : Maximum Stopped Trains = 5
    Explanation : If train no. 1 will left to go without stoppage then 2 and 6 can 
    easily be accommodated on platform 1. And 3 and 4 on platform 2 and 5 on platform 3.

    Input : n = 1, m = 3
    Train no.|Arrival Time|Dept. Time | Platform No.
        1    | 10:00      |  10:30    |    1
        2    | 11:10      |  11:30    |    1
        3    | 12:00      |  12:20    |    1
            
    Output : Maximum Stopped Trains = 3
    Explanation : All three trains can be easily stopped at platform 1.
 * Resources:
 *  
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
        int n, m;
        si(n), si(m);

        vpii trains_on_platform[n + 1];
        fo(i, 0, m)
        {
            int arr, dept, plat;
            si(arr), si(dept), si(plat);

            trains_on_platform[plat].pb(mp(arr, dept));
        }

        fo(i, 1, n + 1) 
        {
            sort(all(trains_on_platform[i]), [](pii a, pii b){
                return a.se < b.se;
            });
        }

        int stopped_trains = 0;
        fo(i, 1, n + 1)
        {
            if (trains_on_platform[i].empty()) continue;

            int curr = 0;
            ++stopped_trains;

            fo(j, 1, trains_on_platform[i].size())
            {
                if (trains_on_platform[i][j].fi >= trains_on_platform[i][curr].se)
                {
                    ++stopped_trains;
                    curr = j;
                }
            }
        }

        pi(stopped_trains);
    }

    return 0;
}