#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.spoj.com/problems/AGGRCOW/
 * Description:
    Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. 
    The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

    His C (2 <= C <= N) cows don't like this barn layout and become aggressive 
    towards each other once put into a stall. 
    To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, 
    such that the minimum distance between any two of them is as large as possible. 
    What is the largest minimum distance?

    Input:
    1
    5 3
    1
    2
    8
    4
    9

    Output:
    3

    Output details:
    FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
    resulting in a minimum distance of 3.
 * Resources:
 *  https://medium.com/@rushyab/aggressive-cows-spoj-75a155bfe749
 * 
*************************************************************************************************************/

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define ss(s) getline(cin, s)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ps(s) cout << s << "\n"
#define fo(i, k, n) for (int i = k; i < n; i++)
#define rof(i, k, n) for (int i = k; i > 0; i--)
#define ll long long
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

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

bool is_possible(int arr[], int n, int dist, int num_cows)
{
    int pos = arr[0];
    int num_placed = 1;
    fo(i, 1, n)
    {
        if (arr[i] - pos >= dist)
        {
            pos = arr[i];
            ++num_placed;

            if (num_placed == num_cows) return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t{0};
    si(t);

    while (t--)
    {
        int n{0}, num_cows{0};
        si(n);
        si(num_cows);

        int arr[n] = {0};
        fo(i, 0, n) si(arr[i]);

        sort(arr, arr + n);

        int min_dist{-1}, lo{0}, hi{arr[n - 1]};
        while (lo <= hi)
        {
            int mid{lo + (hi - lo) / 2};
            if (is_possible(arr, n, mid, num_cows))
            {
                min_dist = max(min_dist, mid);
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }

        pi(min_dist);
    }

    return 0;
}