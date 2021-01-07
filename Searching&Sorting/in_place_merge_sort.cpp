#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/in-place-merge-sort/
 * Description:
    Implement Merge Sort i.e. standard implementation keeping the sorting algorithm as in-place.
    In-place means it does not occupy extra memory for merge operation as in standard case.

    Examples:

    Input: arr[] = {2, 3, 4, 1}
    Output: 1 2 3 4

    Input: arr[] = {56, 2, 45}
    Output: 2 45 56
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

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

void merge(int arr[], int l1, int m, int r)
{
    int l2 = m + 1;
    if (arr[m] <= arr[l1])
        return;

    while (l1 <= m && l2 <= r)
    {
        if (arr[l1] < arr[l2])
            ++l1;
        else
        {
            int val{arr[l2]}, idx{l2};
            while (l2 != l1)
            {
                arr[idx] = arr[idx - 1];
                idx--;
            }
            arr[idx] = val;
            ++l1;
            ++l2;
            ++m;
        }
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
        int n{0};
        si(n);

        int arr[n] = {0};
        fo(i, 0, n) si(arr[i]);

        merge_sort(arr, 0, n - 1);

        fo(i, 0, n) cout << arr[i] << " ";
        cout << "\n";
    }

    return 0;
}