#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0
 * Description:
    Given a string S, find the longest palindromic substring in S. 
    Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). 
    Palindrome string: A string which reads the same backwards. 
    More formally, S is palindrome if reverse(S) = S. 
    Incase of conflict, return the substring which occurs first ( with the least starting index ).

    NOTE: Required Time Complexity O(n2).
 * Resources:
 *  https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
 *  https://www.geeksforgeeks.org/longest-palindrome-substring-set-2/
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
        string s;
        ss(s);

        int max_length{1}, start{0};
        int len = s.length();

        for (int i{1}; i < len; i++)
        {
            int low{i - 1}, high{i};

            while (low >= 0 && high <= len - 1 && s.at(low) == s.at(high))
            {
                if (high - low + 1 > max_length)
                {
                    max_length = high - low + 1;
                    start = low;
                }
                --low;
                ++high;
            }

            low = i - 1;
            high = i + 1;
            
            while (low >= 0 && high <= len - 1 && s.at(low) == s.at(high))
            {
                if (high - low + 1 > max_length)
                {
                    max_length = high - low + 1;
                    start = low;
                }
                --low;
                ++high;
            }
        }

        ps(s.substr(start, max_length));
    }

    return 0;
}