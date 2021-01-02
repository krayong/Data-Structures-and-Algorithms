#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings
 * Description:
    Check if a string is the valid shuffle of two other strings in Java
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

bool checkShuffle(string str1, string str2, string result)
{
    if (str1.length() + str2.length() != result.length())
        return false;

    int i{0}, j{0}, k{0};
    while (k != result.length())
    {
        if (i < str1.length() && str1.at(i) == result.at(k))
            i++;
        else if (j < str2.length() && str2.at(j) == result.at(k))
            j++;
        else
            return false;

        k++;
    }

    if (i < str1.length() || j < str2.length())
        return false;

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
        string str1, str2, result;
        ss(str1);
        ss(str2);
        ss(result);

        ps(checkShuffle(str1, str2, result));
    }

    return 0;
}