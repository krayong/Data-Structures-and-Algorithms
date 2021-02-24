#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/
 * Description:
    A board of length m and width n is given, we need to break this board into m*n squares 
    such that cost of breaking is minimum. cutting cost for each edge will be given for the board. 
    In short we need to choose such a sequence of cutting such that cost is minimized.

    Examples:

    Board:
    https://media.geeksforgeeks.org/wp-content/cdn-uploads/board.png

    For above board optimal way to cut into square is: Total minimum cost in above case is 42. 
    It is evaluated using following steps.

    Initial Value : Total_cost = 0
    Total_cost = Total_cost + edge_cost * total_pieces

    Cost 4 Horizontal cut         Cost = 0 + 4*1 = 4
    Cost 4 Vertical cut        Cost = 4 + 4*2 = 12
    Cost 3 Vertical cut        Cost = 12 + 3*2 = 18
    Cost 2 Horizontal cut        Cost = 18 + 2*3 = 24
    Cost 2 Vertical cut        Cost = 24 + 2*3 = 30
    Cost 1 Horizontal cut        Cost = 30 + 1*4 = 34
    Cost 1 Vertical cut        Cost = 34 + 1*4 = 38
    Cost 1 Vertical cut        Cost = 38 + 1*4 = 42
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
#define ll long long
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define rof(i, k, n) for (ll i = k; i >= n; i--)
#define deb(x) cout << #x << "=" << x << "\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define set(x, i) memset(x, i, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(a, it) for (auto it = a.begin(); it != a.end(); it++)
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define randomize srand(chrono::high_resolution_clock::now().time_since_epoch().count())

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
    fastio;
    randomize;

    int t;
    si(t);

    while (t--)
    {
        int m, n;
        si(m), si(n);

        int row_cut_cost[m - 1], col_cut_cost[n - 1];
        fo(i, 0, m - 1) si(row_cut_cost[i]);
        fo(i, 0, n - 1) si(col_cut_cost[i]);

        sort(row_cut_cost, row_cut_cost + m - 1, greater<int>());
        sort(col_cut_cost, col_cut_cost + n - 1, greater<int>());

        int horizontal_pieces = 1, vertical_pieces = 1;
        int total_cost = 0;

        int i = 0, j = 0;
        while (i < m - 1 && j < n - 1)
        {
            if (row_cut_cost[i] < col_cut_cost[j])
            {
                total_cost += col_cut_cost[j++] * horizontal_pieces;
                ++vertical_pieces;
            }
            else if (row_cut_cost[i] > col_cut_cost[j])
            {
                total_cost += row_cut_cost[i++] * vertical_pieces;
                ++horizontal_pieces;
            }
            else
            {
                total_cost += col_cut_cost[j++] * horizontal_pieces;
                ++vertical_pieces;
                
                total_cost += row_cut_cost[i++] * vertical_pieces;
                ++horizontal_pieces;
            }
        }

        while (i < m - 1)
        {
            total_cost += row_cut_cost[i++] * vertical_pieces;
            ++horizontal_pieces;
        }

        while (j < n - 1)
        {
            total_cost += col_cut_cost[j++] * horizontal_pieces;
            ++vertical_pieces;
        }

        cout << "Total cost to cut the board is: " << total_cost << "\n";
    }

    return 0;
}