#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/number-swaps-sort-adjacent-swapping-allowed/
 * Description:
    Given an array arr[] of non negative integers. 
    We can perform a swap operation on any two adjacent elements in the array. 
    Find the minimum number of swaps needed to sort the array in ascending order.
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

int merge(int a[], int temp[], int start, int mid, int end)
{
    int i{start}, j{mid}, k{start}, inversion_count{0};
    while ((i <= mid - 1) && (j <= end))
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
        {
            temp[k++] = a[j++];
            inversion_count += mid - i;
        }
    }

    while (i <= mid - 1)
        temp[k++] = a[i++];

    while (j <= end)
        temp[k++] = a[j++];

    for (i = start; i <= end; i++)
        a[i] = temp[i];

    return inversion_count;
}

int merge_sort(int a[], int temp[], int start, int end)
{
    int inversion_count{0};
    if (start < end)
    {
        int mid = (end + start) / 2;

        inversion_count += merge_sort(a, temp, start, mid);
        inversion_count += merge_sort(a, temp, mid + 1, end);

        inversion_count += merge(a, temp, start, mid + 1, end);
    }

    return inversion_count;
}

int min_adjacent_swaps(int arr[], int n)
{
    int temp[n] = {0};
    return merge_sort(arr, temp, 0, n - 1);
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
        fo(i, n) si(arr[i]);

        ps(min_adjacent_swaps(arr, n));
    }

    return 0;
}