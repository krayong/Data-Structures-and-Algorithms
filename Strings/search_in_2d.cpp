#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/find-the-string-in-grid/0
 * Description:
    Given a 2D grid (G[]) of characters and a word(x), find all occurrences of given word in grid. 
    A word can be matched in all 8 directions at any point. 
    Word is said be found in a direction if all characters match in this direction (not in zig-zag form).

    The 8 directions are, Horizontally Left, Horizontally Right, 
    Vertically Up, Vertically down and 4 Diagonal directions.
 * Resources:
 *  https://www.geeksforgeeks.org/search-a-word-in-a-2d-grid-of-characters/
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

bool search2d(char grid[][100], int row_max, int col_max, string pattern, int r, int c)
{
    int x[] = {0, 0, -1, 1, -1, -1, 1, 1};
    int y[] = {-1, 1, 0, 0, 1, -1, 1, -1};

    int len = pattern.length();

    for (int dir = 0; dir < 8; dir++)
    {
        int k, rd = r + x[dir], cd = c + y[dir];

        for (k = 1; k < len; k++)
        {
            if (rd >= row_max || rd < 0 || cd >= col_max || cd < 0)
                break;

            if (grid[rd][cd] != pattern[k])
                break;

            rd += x[dir];
            cd += y[dir];
        }

        if (k == len)
            return true;
    }

    return false;
}

void search(char grid[][100], int r, int c, string pattern)
{
    fo(i, r)
    {
        fo(j, c)
        {
            if (grid[r][c] == pattern[0])
                if (search2d(grid, r, c, pattern, i, j))
                    cout << "Pattern found at row " << i << " and column " << j << "\n";
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
        int r{0}, c{0};
        si(r);
        si(c);

        char grid[r][c];
        fo(i, r) fo(j, c) cin >> grid[r][c];

        string pattern;
        ss(pattern);

        search(grid, r, c, pattern);
    }

    return 0;
}