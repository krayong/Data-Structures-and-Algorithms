#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                            Boyer Moore
 * Link : https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/
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
 *  https://www.geeksforgeeks.org/boyer-moore-algorithm-good-suffix-heuristic/
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

#define NUM_OF_CHARS 256

void init_bad_chars(string pattern, int bad_char[])
{
    for (int i = 0; i < pattern.length(); i++)
        bad_char[static_cast<int>(pattern[i])] = i;
}

void bad_heuristic_search(string text, string pattern)
{
    int m{pattern.length()}, n{text.length()};

    int bad_char[NUM_OF_CHARS];
    memset(bad_char, -1, NUM_OF_CHARS);

    init_bad_chars(pattern, bad_char);

    int s{0};
    while (s <= n - m)
    {
        int j{m - 1};
        while (j >= 0 && text[s + j] == pattern[j])
            j--;

        if (j < 0)
        {
            cout << "Pattern found at index " << s << "\n";
            s += (s + m < n) ? m - bad_char[text[s + m]] : 1;
        }
        else
            s += max(1, j - bad_char[text[s + j]]);
    }
}

void preprocess_suffix(int *shift, int *bpos, string pattern)
{
    int m{pattern.length()};
    int i{m}, j{m + 1};
    bpos[i] = j;

    while (i > 0)
    {
        while (j <= m && pattern[i - 1] != pattern[j - 1])
        {
            if (shift[j] == 0)
                shift[j] = j - i;

            j = bpos[j];
        }
        i--;
        j--;
        bpos[i] = j;
    }

    j = bpos[0];
    for (i = 0; i <= m; i++)
    {
        if (shift[i] == 0)
            shift[i] = j;

        if (i == j)
            j = bpos[j];
    }
}

void good_suffix_search(string text, string pattern)
{
    int m{pattern.length()}, n{text.length()};

    int bpos[m + 1], shift[m + 1];
    memset(shift, 0, m + 1);

    preprocess_suffix(shift, bpos, pattern);

    int s{0};
    while (s <= n - m)
    {
        int j{m - 1};
        while (j >= 0 && text[s + j] == pattern[j])
            j--;

        if (j < 0)
        {
            cout << "Pattern found at index " << s << "\n";
            s += shift[0];
        }
        else
            s += shift[j + 1];
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

        bad_heuristic_search(text, pattern);
        good_suffix_search(text, pattern);
    }

    return 0;
}