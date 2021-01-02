#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://leetcode.com/problems/merge-intervals/
 * Description:
    Given a collection of intervals, merge all overlapping intervals.

    Example 1:

    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

 * Resources:
    https://leetcode.com/problems/merge-intervals/discuss/482195/C%2B%2B-9-lines-99-Run-Time-Easy-to-understand-solution
 * 
*************************************************************************************************************/

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define ss(s) getline(cin, s)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ps(s) cout << s << "\n"
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

void print(const vpii &arr)
{
    cout << "[";
    for (auto ele: arr)
    {
        cout << "[" << ele.first << ", " << ele.second << "] ";  
    }
    cout << "]\n";
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
        vpii arr;
        fo(i, n)
        {
            int first, second;
            si(first);
            si(second);
            arr.pb(mp(first, second));
        }

        if (arr.size() <= 1) print(arr);
        else 
        {
            sort(arr.begin(), arr.end());
            vpii out;
            out.pb(arr.at(0));
            for (int i = 1; i < arr.size(); i++) 
            {
                if (out.back().second >= arr.at(i).first)
                    out.back().second = max(out.back().second, arr.at(i).second);
                else out.pb(arr.at(i));
            }
            print(out);
        }
    }

    return 0;
}