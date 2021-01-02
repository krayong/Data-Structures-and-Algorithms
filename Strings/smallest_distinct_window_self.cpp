#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/smallest-distant-window/0
 * Description:
    Given a string 's', the task is to find the smallest window length that 
    contains all the characters of the given string at least one time.
    
    For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.
 * Resources:
 *  https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
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

        int n = str.length();

        unordered_set<char> us;
        for (char c: str)
            us.insert(c);

        int num_distinct = us.size();

        int start{0}, start_index{0}, min_length{n}, total_chars{0};
        int chars[256] = {0};
        
        for (int i = 0; i < n; i++)
        {
            chars[str[i]]++;

            if (chars[str[i]] == 1) total_chars++;

            if (total_chars == num_distinct) {
                while(chars[str[start]] > 1) {
                    if (chars[str[start]] > 1)
                        chars[str[start]]--;
                    start++;
                }

                int len_window = i - start + 1;
                if (len_window < min_length) {
                    min_length = len_window;
                    start_index = start;
                }
            }
        }

        cout << str.substr(start_index, min_length) << "\n";
    }

    return 0;
}