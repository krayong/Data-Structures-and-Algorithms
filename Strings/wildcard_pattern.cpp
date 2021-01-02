#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/wildcard-pattern-matching/
 * Description:
    Given a text and a wildcard pattern, implement wildcard pattern matching algorithm 
    that finds if wildcard pattern is matched with text. 
    The matching should cover the entire text (not partial text).

    The wildcard pattern can include the characters ‘?’ and ‘*’ 
    ‘?’ – matches any single character 
    ‘*’ – Matches any sequence of characters (including the empty sequence)
 * Resources:
 *  https://www.geeksforgeeks.org/dynamic-programming-wildcard-pattern-matching-linear-time-constant-space/
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

bool match(string str, string pat)
{
    int n{str.length()}, m{pat.length()};

    if (m == 0)
        return (n == 0);

    int i{0}, j{0}, index_str{-1}, index_pat{-1};
    while (i < n)
    {
        if (j < m && str[i] == pat[j])
        {
            i++;
            j++;
        }
        else if (j < m && pat[j] == '?')
        {
            i++;
            j++;
        }
        else if (j < m && pat[j] == '*')
        {
            index_str = i;
            index_pat = j;
            j++;
        }
        else if (j < m && index_pat != -1)
        {
            i = index_str + 1;
            j = index_pat + 1;
            index_str++;
        }
        else
            return false;
    }

    while (j < m && pat[j] == '*')
        j++;

    return (j == m);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t{0};
    si(t);

    while (t--)
    {
        string str, pat;
        ss(str);
        ss(pat);
        if (match(str, pat))
            ps("Yes");
        else
            ps("No");
    }

    return 0;
}