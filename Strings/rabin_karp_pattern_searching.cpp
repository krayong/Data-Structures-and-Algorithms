#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                           Rabin Karp   
 * Link : https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
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

void search(string text, string pattern, int prime = 101)
{
    short chars{256}; // total characters possible

    int m{pattern.length()}, n{text.length()};

    int p{0}, t{0}, hash{1};

    for (int i = 0; i < m - 1; i++)
        hash = (hash * chars) % prime;

    for (int i = 0; i < m; i++)
    {
        p = (p * chars + pattern[i]) % prime; // hash value of pattern
        t = (t * chars + text[i]) % prime;    // hash value of text[0...m)
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (p == t) // pattern hash and text[i...i+m) hash are same
        {
            int j;
            for (j = 0; j < m; j++)
                if (pattern[j] != text[i + j])
                    break;

            if (j == m)
                cout << "Pattern found at index: " << i << "\n";
        }

        if (i < n - m)
        {
            t = (chars * (t - text[i] * hash) + text[i + m]) % prime; // hash of text[i+1...i+m]
            if (t < 0)
                t += prime;
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
        string text, pattern;
        ss(text);
        ss(pattern);

        search(text, pattern);
    }

    return 0;
}