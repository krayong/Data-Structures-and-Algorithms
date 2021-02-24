#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/find-maximum-meetings-in-one-room/
 * Description:
    There is one meeting room in a firm. There are N meetings in the form of 
    (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is finish 
    time of meeting i. The task is to find the maximum number of meetings that 
    can be accommodated in the meeting room. Print all meeting numbers.

    Examples: 

    Input : 
    s[] = {1, 3, 0, 5, 8, 5}, 
    f[] = {2, 4, 6, 7, 9, 9} 
    Output : 1 2 4 5 
    Explanation:
    First meeting [1, 2] 
    Second meeting [3, 4] 
    Fourth meeting [5, 7] 
    Fifth meeting [8, 9]

    Input : 
    s[] = { 75250,  50074, 43659,  , 11273, 27545, 50879, 77924}, 
    f[] = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252} 
    Output : 6 7 1 
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

vi find_meetings(pair<int, pii> meetings[], int n)
{
    sort(meetings, meetings + n, [](pair<int, pii> a, pair<int, pii> b) {
        return a.se.se < b.se.se;
    });

    int meeting_end = meetings[0].se.se;

    vi acc_meetings;
    acc_meetings.pb(meetings[0].fi);

    fo(i, 1, n)
    {
        if (meetings[i].se.fi > meeting_end)
        {
            acc_meetings.pb(meetings[i].fi);
            meeting_end = meetings[i].se.se;
        }
    }

    return acc_meetings;
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

        pair<int, pii> meetings[n];
        fo(i, 0, n)
        {
            meetings[i].fi = i + 1;
            si(meetings[i].se.fi), si(meetings[i].se.se);
        }

        vi meeting_numbers = find_meetings(meetings, n);
        for (int i : meeting_numbers)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}