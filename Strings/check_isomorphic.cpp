#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1
 * Description:
    Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
    Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible 
    for every character of str1 to every character of str2 while preserving the order.
 * Resources:
 *  https://uploads.disquscdn.com/images/8f9ca7576ee0f08fca06c1f1f96ee4e4c279cbbd1539dda2eb226e77c9d19777.png
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
#define fi first
#define se second
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

bool check_isomorphic(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    int hash1[256] = {0}, hash2[256] = {0};
    for (int i{0}; i < str1.length(); i++)
    {
        if (hash1[str1[i]] == 0 && hash2[str2[i]] == 0)
        {
            hash1[str1[i]] = (int)str2[i];
            hash2[str2[i]] = (int)str1[i];
        }
        else if (hash1[str1[i]] != (int)str2[i] || hash2[str2[i]] != (int)str1[i])
            return false;
    }
    return true;
}

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

        ps(check_isomorphic(str1, str2));
    }

    return 0;
}