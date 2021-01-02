#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0
 * Description:
   Given a string S. The task is to print all permutations of a given string.
 * Resources:
 *  https://www.geeksforgeeks.org/distinct-permutations-of-a-string-containing-duplicates-using-hashset-in-java
 *  https://www.geeksforgeeks.org/print-distinct-sorted-permutations-with-duplicates-allowed/
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

unordered_set<string> us;

void permutation(string s, int i, int n)
{
    if (i == n)
    {
        if (us.find(s) == us.end())
        {
            us.insert(s);
        }
    }
    else
    {
        for (int j = i; j <= n; j++)
        {
            swap(s.at(i), s.at(j));
            permutation(s, i + 1, n);
            swap(s.at(j), s.at(i));
        }
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

        permutation(str, 0, str.length() - 1);

        for (string s : us)
            ps(s);
    }

    return 0;
}