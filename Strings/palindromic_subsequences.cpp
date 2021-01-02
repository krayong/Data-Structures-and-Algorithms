#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1
 * Description:
    Given a string str of length N, you have to find number of palindromic subsequence 
    (need not necessarily be distinct) which could be formed from the string str.
 * Resources:
 *  https://www.geeksforgeeks.org/count-palindromic-subsequence-given-string/
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

int count_ps(string str, unordered_map<string, int> &um, int i, int j)
{
    if (i > j)
        return 0;
    else if (i == j)
        return 1;
    else if (um.find(str.substr(i, j - i + 1)) != um.end())
        return um.at(str.substr(i, j - i + 1));
    else if (str[i] == str[j])
    {
        int num = 1 + count_ps(str, um, i, j - 1) + count_ps(str, um, i + 1, j);
        um.insert(mp(str.substr(i, j - i + 1), num));
        return num;
    }
    else
    {
        int num = count_ps(str, um, i, j - 1) + count_ps(str, um, i + 1, j) - count_ps(str, um, i + 1, j - 1);
        um.insert(mp(str.substr(i, j - i + 1), num));
        return num;
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t{0};
    si(t);

    while (t--)
    {
        string str;
        ss(str);

        unordered_map<string, int> um;
        cout << count_ps(str, um, 0, str.length() - 1) << "\n";
    }

    return 0;
}