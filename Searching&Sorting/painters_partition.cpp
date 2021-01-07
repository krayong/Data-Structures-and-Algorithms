#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/painters-partition-problem/
 * Description:
    We have to paint n boards of length {A1, A2…An}. 
    There are k painters available and each takes 1 unit time to paint 1 unit of board. 
    The problem is to find the minimum time to get
    this job done under the constraints that any painter will only paint continuous sections of boards, 
    say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.

    Examples:

    Input : k = 2, A = {10, 10, 10, 10} 
    Output : 20.
    Here we can divide the boards into 2 equal sized partitions, so each painter 
    gets 20 units of board and the total time taken is 20. 

    Input : k = 2, A = {10, 20, 30, 40} 
    Output : 60.
    Here we can divide first 3 boards for one painter and the last board for second painter.
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
#define fo(i, k, n) for (int i = k; i < n; i++)
#define rof(i, k, n) for (int i = k; i >= n; i--)
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

bool is_possible(int arr[], int n, int max_length, int num_painters)
{
    int painters_required{1}, total_painted{0};
    fo(i, 0, n)
    {
        if (arr[i] > max_length)
            return false;
        if (total_painted + arr[i] > max_length)
        {
            ++painters_required;
            total_painted = arr[i];

            if (painters_required > num_painters)
                return false;
        }
        else
            total_painted += arr[i];
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t{0};
    si(t);

    while (t--)
    {
        int n{0};
        si(n);

        int arr[n] = {0};
        fo(i, 0, n) si(arr[i]);

        sort(arr, arr + n);

        int num_painters{0};
        si(num_painters);
        if (n < num_painters)
            pi(-1);
        else
        {
            int lo{*max_element(arr, arr + n)}, hi{accumulate(arr, arr + n, 0)}, min_time{INT_MAX};
            while (lo <= hi)
            {
                int mid{lo + (hi - lo) / 2};
                if (is_possible(arr, n, mid, num_painters))
                {
                    min_time = min(mid, min_time);
                    hi = mid - 1;
                }
                else
                    lo = mid + 1;
            }

            pi(min_time);
        }
    }

    return 0;
}