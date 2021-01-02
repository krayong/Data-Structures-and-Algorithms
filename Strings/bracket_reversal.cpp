#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/count-the-reversals/0
 * Description:
    Given a string S consisting only of opening and closing curly brackets '{' and '}' 
    find out the minimum number of reversals required to make a balanced expression.
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

int count_reversals_1(string str)
{
    if (str.length() % 2 == 1)
        return -1;
    int reversals{0}, left{0};
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
            left++;
        else if (str[i] == '}')
            left--;

        if (left < 0)
        {
            left = 1;
            reversals++;
        }
    }
    return reversals + left / 2;
}

int count_reversals_2(string str)
{
    if (str.length() % 2 == 1)
        return -1;
    stack<char> st;
    int reversals{0};
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
            st.push(str[i]);
        else
        {
            if (st.empty())
            {
                reversals++;
                st.push('{');
            }
            else
                st.pop();
        }
    }

    return reversals + st.size() / 2;
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

        cout << count_reversals_1(str) << "\n";
        cout << count_reversals_2(str) << "\n";
    }

    return 0;
}