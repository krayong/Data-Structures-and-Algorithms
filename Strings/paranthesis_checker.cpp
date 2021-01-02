#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
 * Description:
    Given an expression string x. 
    Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
    For example, the function should return 'true' for exp = “[()]{}{[()()]()}” 
    and 'false' for exp = “[(])”.
    Expected Time Complexity: O(|x|)
    Expected Auixilliary Space: O(|x|)
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

        bool match = true;

        stack<char> st;
        for (auto ch : str)
        {
            if (ch == '[' || ch == '{' || ch == '(') st.push(ch);
            else if (st.empty()) 
            {
                match = false;
                break;
            }
            else {
                char ob = st.top();
                st.pop();
                if (!((ob == '[' && ch == ']') || (ob == '{' && ch == '}') || (ob == '(' && ch == ')'))) 
                {
                    match = false;
                    break;
                } 
            }
        }

        if (st.empty() && match) ps("true");
        else ps("false");
    }

    return 0;
}