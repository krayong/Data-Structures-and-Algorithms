#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : http://theoryofprogramming.com/2017/12/16/find-pivot-element-sorted-rotated-array/
 * Description:
    Suppose we have a sorted array, and now we rotate it N times, 
    find the pivot element. The pivot element would be the largest element. 
    Also, can you calculate N?
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
#define fi first
#define se second
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
        int n{0};
        si(n);

        int arr[n] = {0};
        fo(i, n) si(arr[i]);

        int lo{0}, hi{n - 1};
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] >= arr[(mid - 1) % n] && arr[mid] >= arr[(mid + 1) % n])
                break;
            else if (arr[mid] > arr[hi])
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        int pivot_point = lo + (hi - lo) / 2;

        cout << "The pivot point is: " << pivot_point << " and no of rotations are: " << (pivot_point + 1) << "\n";
    }

    return 0;
}