#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1
 * Description:
    Given two sorted arrays arr1[] of size M and arr2[] of size N. 
    Each array is sorted in non-decreasing order. 
    Merge the two arrays into one sorted array in non-decreasing order without using any extra space.

    Expected Time Complexity: O((m + n)*log(m + n))
    Expected Auxiliary Space: O(1)
 * Resources:
    https://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/
    https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/
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
        int m{0}, n{0};
        si(m);
        si(n);
        int a[m], b[n];
        fo(i, m) si(a[i]);
        fo(i, n) si(b[i]);

        int p{m-1}, q{0};
        while (p >= 0 && q < n) 
        {
            if (a[p] > b[q]) swap(a[p], b[q]);
            else break;
            p--;
            q++;
        }

        sort(a, a+m);
        sort(b, b+n);
    }

    return 0;
}