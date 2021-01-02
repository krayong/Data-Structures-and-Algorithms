#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                            KMP
 * Link : https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
 * Description:
    Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) 
    that prints all occurrences of pat[] in txt[]. You may assume that n > m.
    
    Examples:
    Input:  txt[] = "THIS IS A TEST TEXT"
            pat[] = "TEST"
    Output: Pattern found at index 10

    Input:  txt[] =  "AABAACAADAABAABA"
            pat[] =  "AABA"
    Output: Pattern found at index 0
            Pattern found at index 9
            Pattern found at index 12

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

void lps_array(string pattern, int lps[])
{
    int m{pattern.length()}, len{0};
    lps[0] = 0;

    int i{1};
    while (i < m)
    {
        if (pattern[i] == pattern[len])
            lps[i++] = ++len;
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
}

void kmp_search(string text, string pattern)
{
    int m{pattern.length()}, n{text.length()};

    int lps[m];
    lps_array(pattern, lps);

    int i{0}, j{0};
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << "Pattern found at index: " << i - j << "\n";
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
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
        string pattern, text;
        ss(text);
        ss(pattern);

        kmp_search(text, pattern);
    }

    return 0;
}