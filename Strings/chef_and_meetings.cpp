#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.codechef.com/FEB21C/problems/MEET
 * Description:
    A time is a string in the format "HH:MM AM" or "HH:MM PM" (without quotes), where HH and MM 
    are always two-digit numbers. A day starts at 12:00 AM and ends at 11:59 PM. 

    Chef has scheduled a meeting with his friends at a time P. He has N friends (numbered 1 through N); 
    for each valid i, the i-th friend is available from a time Li to a time Ri (both inclusive). 
    For each friend, can you help Chef find out if this friend will be able to attend the meeting? 
    More formally, check if Li≤P≤Ri for each valid i.

    Input:
    The first line of the input contains a single integer T denoting the number of test cases. 
    The description of T test cases follows.
    The first line of each test case contains a single time P.
    The second line contains a single integer N.
    N lines follow. For each valid i, the i-th of these lines contains two space-separated times Li and Ri.
    
    Output:
    For each test case, print a single line containing one string with length N. For each valid i, 
    the i-th character of this string should be '1' if i-th friend will be able to attend the meeting 
    or '0' otherwise.

    Constraints:
    1≤T≤500
    1≤N≤500
    Each time is valid in the 12-hour clock format 
    For each valid i, the time Ri is greater or equal to Li

    Example Input
    2 ----- t

    12:01 AM ----- p1
    4 ----- n1
    12:00 AM 11:42 PM
    12:01 AM 11:59 AM
    12:30 AM 12:00 PM
    11:59 AM 11:59 PM

    04:12 PM ----- p2
    5 ----- n2
    12:00 AM 11:59 PM
    01:00 PM 04:12 PM
    04:12 PM 04:12 PM
    04:12 AM 04:12 AM
    12:00 PM 11:59 PM

    Example Output:
    1100
    11101

    Explanation:
    Example case 1:
    Friend 1: 12:01 AM lies between 12:00 AM and 11:42 PM 
    (that is, between 00:00 and 23:42 in the 24-hour clock format), 
    so this friend will be able to attend the meeting.

    Friend 2: 12:01 AM lies between 12:01 AM and 11:59 AM 
    (between 00:01 and 11:59 in the 24-hour clock format).

    Friend 3: 12:01 AM does not lie between 12:30 AM and 12:30 PM 
    (between 00:30 and 12:30 in the 24-hour clock format), 
    so this friend will not be able to attend the meeting.

    Friend 4: 12:01 AM does not lie between 11:59 AM and 11:59 PM 
    (between 11:59 and 23:59 in the 24-hour clock format).

    Example case 2: 
    For friend 3, 04:12 PM lies between 04:12 PM and 04:12 PM (inclusive) 
    and hence this friend will be able to attend the meeting.
 * Resources:
 *  https://www.codechef.com/FEB21C/status/MEET?sort_by=All&sorting_order=asc&language=44&status=15&handle=&Submit=GO
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

int convert_to_minutes(string time, string period)
{
    int time_in_minutes = 0;

    if (time.substr(0, 2) == "12")
    {
        if (period == "AM")
            time = "00:" + time.substr(3, 2);
        else
            period = "AM";
    }

    time_in_minutes += stoi(time.substr(0, 2)) * 60;
    time_in_minutes += stoi(time.substr(3, 2));

    if (period == "PM")
        time_in_minutes += 60 * 12;

    return time_in_minutes;
}

vs split_string(string s)
{
    vs splits;

    stringstream check(s);
    string intermediate;

    while (getline(check, intermediate, ' '))
        splits.pb(intermediate);

    return splits;
}

int main()
{
    int t;
    si(t);

    while (t--)
    {
        string p;
        ss(p);

        vs chef_time_splits = split_string(p);
        int chef_time = convert_to_minutes(chef_time_splits[0], chef_time_splits[1]);

        int n;
        si(n);

        while (n--)
        {
            string friend_time;
            ss(friend_time);

            vs friend_time_splits = split_string(friend_time);

            int friend_start_time = convert_to_minutes(friend_time_splits[0], friend_time_splits[1]);
            int friend_end_time = convert_to_minutes(friend_time_splits[2], friend_time_splits[3]);

            if (friend_start_time <= chef_time && chef_time <= friend_end_time)
                cout << "1";
            else
                cout << "0";
        }

        cout << "\n";
    }

    return 0;
}