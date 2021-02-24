#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
 * Description:
    Given a set of N jobs where each job i has a deadline and profit associated to it. 
    Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
    We earn the profit if and only if the job is completed by its deadline. 
    The task is to find the maximum profit and the number of jobs done.

    Note: Jobs will be given in the form (Job id, Deadline, Profit) associated to that Job.

    Examples:

    Input:
    N = 4
    Jobs = (1,4,20)(2,1,10)(3,1,40)(4,1,30)
    Output: 2 60
    Explanation: 2 jobs can be done with maximum profit of 60 (20+40).

    Input:
    N = 5
    Jobs = (1,2,100)(2,1,19)(3,2,27)(4,1,25)(5,1,15)
    Output: 2 127
    Explanation: 2 jobs can be done with maximum profit of 127 (100+27).

    Expected Time Complexity: O(NlogN)
    Expected Auxilliary Space: O(N)

    Constraints:
    1 <= N <= 100
    1 <= Deadline <= 100
    1 <= Profit <= 500
 * Resources:
 *  https://www.geeksforgeeks.org/weighted-job-scheduling/
 *  https://www.geeksforgeeks.org/weighted-job-scheduling-log-n-time/
 *  https://www.geeksforgeeks.org/job-sequencing-using-disjoint-set-union/
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

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

struct Job {
    int job_id, deadline, profit;
};

pii schedule_jobs(Job jobs[], int n)
{
    sort(jobs, jobs + n, [](Job a, Job b){
        return a.deadline < b.deadline;
    });

    unordered_set<int> deadlines;

    deadlines.insert(jobs[0].deadline);
    int max_profit = jobs[0].profit;

    fo(i, 1, n)
    {
        rof(j, jobs[i].deadline, 1)
        {
            if (deadlines.find(j) == deadlines.end())
            {
                deadlines.insert(j);
                max_profit += jobs[i].profit;
                break;
            }
        }
    }

    return mp(deadlines.size(), max_profit);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t;
    si(t);

    while (t--)
    {
        int n;
        si(n);

        Job jobs[n];
        fo(i, 0, n) si(jobs[i].job_id), si(jobs[i].deadline), si(jobs[i].profit);

        auto completed_jobs = schedule_jobs(jobs, n);

        cout << "Number of jobs completed: " << completed_jobs.fi << "\n";
        cout << "Maximum profit is: " << completed_jobs.se << "\n";
    }

    return 0;
}