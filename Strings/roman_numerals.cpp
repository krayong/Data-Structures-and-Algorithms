#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1
 * Description:
    Given a string in roman no format(s) your task is to convert it to an integer . 
    Various symbols and their values are given below.
    I 1
    V 5
    X 10
    L 50
    C 100
    D 500
    M 1000
 * Resources:
 *  https://www.geeksforgeeks.org/converting-roman-numerals-decimal-lying-1-3999/
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
        string roman;
        ss(roman);

        unordered_map<char, int> value_map({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}});

        int decimal{0};
        for (int i = 0; i < roman.length(); i++)
        {
            int ch = value_map.at(roman[i]);
            if (i + 1 < roman.length())
            {
                int next_ch = value_map.at(roman[i + 1]);
                if (ch >= next_ch)
                    decimal += ch;
                else
                {
                    decimal += next_ch - ch;
                    i++;
                }
            }
            else
                decimal += ch;
        }

        pi(decimal);
    }

    return 0;
}