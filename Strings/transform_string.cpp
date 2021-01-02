#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/transform-one-string-to-another-using-minimum-number-of-given-operation/
 * Description:
    Given two strings A and B, the task is to convert A to B if possible. 
    The only operation allowed is to put any character from A and insert it at front. 
    Find if it’s possible to convert the string. 
    If yes, then output minimum no. of operations required for transformation.

    Examples:
    Input:  A = "ABD", B = "BAD"
    Output: 1
    Explanation: Pick B and insert it at front.

    Input:  A = "EACBD", B = "EABCD"
    Output: 3
    Explanation: Pick B and insert at front, EACBD => BEACD
                Pick A and insert at front, BEACD => ABECD
                Pick E and insert at front, ABECD => EABCD
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

int transform(string str1, string str2)
{
    if (str1.size() != str2.size())
        return -1;

    unordered_map<char, int> um;
    for (char c : str1)
        um[c]++;
    for (char c : str2)
        if (um.at(c) == 1)
            um.erase(um.find(c));
        else
            um[c]--;

    if (um.size() != 0)
        return -1;

    int num_transforms{0};
    for (int i{str1.size() - 1}, j{str2.size() - 1}; i >= 0;)
    {
        while (i >= 0 && str1[i] != str2[j])
        {
            i--;
            num_transforms++;
        }

        if (i >= 0)
        {
            i--;
            j--;
        }
    }

    return num_transforms;
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

        ps(transform(str1, str2));
    }

    return 0;
}