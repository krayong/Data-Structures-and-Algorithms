#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x/0
 * Description:
    Given a sorted array with possibly duplicate elements, 
    the task is to find indexes of first and last occurrences of an element x in the given array.
 * Resources:
 *  https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/
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

int first_index(int arr[], int n, int x)
{
    int first{0}, last{n - 1};

    while (first <= last)
    {
        int mid = first + (last - first) / 2;
        if (arr[mid] == x && (mid == 0 || arr[mid - 1] != x))
            return mid;
        else if (arr[mid] >= x)
            last = mid - 1;
        else
            first = mid + 1;
    }

    return -1;
}

int last_index(int arr[], int n, int x)
{
    int first{0}, last{n - 1};

    while (first <= last)
    {
        int mid = first + (last - first) / 2;
        if (arr[mid] == x && (mid == n - 1 || arr[mid + 1] != x))
            return mid;
        else if (arr[mid] > x)
            last = mid - 1;
        else
            first = mid + 1;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t{0};
    si(t);

    while (t--)
    {
        int n{0}, x{0};
        si(n);
        si(x);

        int arr[n];
        fo(i, n) si(arr[i]);

        int first_occurence = first_index(arr, n, x);
        int last_occurence = last_index(arr, n, x);

        cout << first_occurence << " " << last_occurence << "\n";
    }

    return 0;
}