#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0
 * Description:
 *  
 * Resources:
 *  https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
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
        int r{0}, c{0};
        si(r);
        si(c);

        int arr[r][c];
        fo(i, r)
        {
            fo(j, c)
            {
                si(arr[i][j]);
            }
        }

        int k{0}, l{0}; // k is row index, l is column index
        while (k < r && l < c)
        {
            for (int i = l; i < c; i++) cout << arr[k][i] << " ";
            k++;

            for (int i = k; i < r; i++) cout << arr[i][c - 1] << " ";
            c--;

            if (k < r)
            {
                for (int i = c - 1; i >= l; i--) cout << arr[r - 1][i] << " ";
                r--;
            }

            if (l < c) 
            {
                for (int i = r - 1; i >= k; i--) cout << arr[i][l] << " ";
                l++;
            }
        }
    }

    return 0;
}