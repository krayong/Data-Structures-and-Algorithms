#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
 * Description:
    There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) 
    where S[i] is start time of meeting i and F[i] is finish time of meeting i.
    What is the maximum number of meetings that can be accommodated in the meeting room 
    when only one meeting can be held in the meeting room at a particular time? 
    Also note start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

    Examples:

    Input:
    N = 6
    S[] = {1,3,0,5,8,5}
    F[] = {2,4,6,7,9,9}
    Output: 4

    Input:
    N = 8
    S[] = { 75250,  50074, 43659,  8931, 11273, 27545, 50879,  77924}
    F[] = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252}
    Output: 3

    Expected Time Complexity : O(N*LogN)
    Expected Auxilliary Space : O(N)

    Constraints:
    1 ≤ N ≤ 105
    0 ≤ S[i] < F[i] ≤ 105
 * Resources:
 *  https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
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

int num_meetings(pii meetings[], int n)
{
    sort(meetings, meetings + n, [](pii a, pii b) {
        return a.se < b.se;
    });

    int meetings_possible = 1, meeting_end = meetings[0].se;

    fo(i, 1, n)
    {
        if (meetings[i].fi > meeting_end)
        {
            ++meetings_possible;
            meeting_end = meetings[i].se;
        }
    }

    return meetings_possible;
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

        pii meetings[n];
        fo(i, 0, n)
            si(meetings[i].fi),
            si(meetings[i].se);

        cout << "Number of meetings that can be help simultaneously are: " << num_meetings(meetings, n) << "\n";
    }

    return 0;
}