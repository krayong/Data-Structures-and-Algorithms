#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/edit-distance3702/1
 * Description:
    Given two strings s and t, find the minimum number of operations that need to be performed on str1 
    to convert it to str2. The possible operations are:
    Insert
    Remove
    Replace

 * Resources:
 *  https://disq.us/url?url=https%3A%2F%2Focw.mit.edu%2Fcourses%2Felectrical-engineering-and-computer-science%2F6-006-introduction-to-algorithms-fall-2011%2Flecture-videos%2FMIT6_006F11_lec21.pdf%3AQAfptwIO2jjAAWOZC-QU-ASEWqw&cuid=3952990
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

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t{0};
    si(t);

    while (t--)
    {
        string str1, str2;
        ss(str1);
        ss(str2);

        int m{str1.length()}, n{str2.length()};

        int dp[m + 1][n + 1];

        fo(i, m)
        {
            fo(j, n)
            {
                if (i == 0) dp[i][j] = j;
                else if (j == 0) dp[i][j] = i;
                else if (str1.at(i - 1) == str2.at(j - 1)) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
            }
        }

        ps(dp[m][n]);
    }

    return 0;
}