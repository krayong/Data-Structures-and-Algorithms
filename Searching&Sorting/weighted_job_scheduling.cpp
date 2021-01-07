#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/weighted-job-scheduling/
 * Description:
    Given N jobs where every job is represented by following three elements of it.

    1. Start Time
    2. Finish Time
    3. Profit or Value Associated (>= 0)
    Find the maximum profit subset of jobs such that no two jobs in the subset overlap. 

    Example:
    Input: Number of Jobs n = 4
        Job Details {Start Time, Finish Time, Profit}
        Job 1:  {1, 2, 50} 
        Job 2:  {3, 5, 20}
        Job 3:  {6, 19, 100}
        Job 4:  {2, 100, 200}
    Output: The maximum profit is 250.
    We can get the maximum profit by scheduling jobs 1 and 4.
    Note that there is longer schedules possible Jobs 1, 2 and 3 
    but the profit with this schedule is 20+50+100 which is less than 250.
 * Resources:
 *  https://www.geeksforgeeks.org/weighted-job-scheduling/
 *  https://www.geeksforgeeks.org/weighted-job-scheduling-log-n-time/
 * 
*************************************************************************************************************/

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define ss(s) getline(cin, s)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ps(s) cout << s << "\n"
#define fo(i, k, n) for (int i = k; i < n; i++)
#define rof(i, k, n) for (int i = k; i >= n; i--)
#define ll long long
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

int latest_non_conflict_ls(vector<pair<int, pii>> jobs, int i)
{
    rof(j, i - 1, 0) if (jobs[j].se.se <= jobs[i].se.fi) return j; // job j's finish time <= job i's start time, so no conflict
    return -1;
}

int latest_non_conflict_bs(vector<pair<int, pii>> jobs, int i)
{
    int lo{0}, hi{i - 1};
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (jobs[mid].se.se <= jobs[i].se.fi)         // job mid's finish time <= job i's start time, so no conflict
            if (jobs[mid + 1].se.se <= jobs[i].se.fi) // job mid + 1's finish time alse <= job i's start time, so more possibilities
                lo = mid + 1;
            else
                return mid;
        else
            hi = mid - 1;
    }
    return -1;
}

int max_profit(vector<pair<int, pii>> jobs)
{
    int n = jobs.size();

    sort(all(jobs), [](pair<int, pii> a, pair<int, pii> b) {
        return a.se.se < b.se.se; // sort by finish time ascending
    });

    int profit_table[n] = {0};
    profit_table[0] = jobs[0].fi;

    fo(i, 1, n)
    {
        int incl_profit{jobs[i].fi};

        // int lnf_idx = latest_non_conflict_ls(jobs, i); // O(n * n) because linear search O(n)
        int lnf_idx = latest_non_conflict_bs(jobs, i); // O(n * logn) because binary search O(logn)

        if (lnf_idx != -1)
            incl_profit += profit_table[lnf_idx];
        profit_table[i] = max(profit_table[i - 1], incl_profit);
    }

    return profit_table[n - 1];
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

        vector<pair<int, pii>> jobs;
        fo(i, 0, n)
        {
            int st_t{0}, fi_t{0}, pf{0};
            si(st_t);
            si(fi_t);
            si(pf);
            jobs.pb(mp(pf, mp(st_t, fi_t)));
        }

        pi(max_profit(jobs));
    }

    return 0;
}