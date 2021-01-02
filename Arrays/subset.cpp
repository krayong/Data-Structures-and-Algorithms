#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/array-subset-of-another-array/0
 * Description:
    Given two arrays: arr1[0..m-1] of size m and arr2[0..n-1] of size n. 
    Task is to check whether arr2[] is a subset of arr1[] or not. 
    Both the arrays can be both unsorted or sorted. 
    It may be assumed that elements in both array are distinct.
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

    int t {0};
    si(t);

    while (t--)
    {
        int m{0}, n{0};
        si(m);si(n);

        int arr1[m], arr2[n];
        unordered_map<int, int> um1, um2;

        fo (i, m) 
        {
            si(arr1[i]);
            um1[arr1[i]]++;
        }

        fo(i, n)
        {
            si(arr2[i]);
            um2[arr2[i]]++;
        }

        bool subset = true;

        for (auto ele: um2) 
        {
            if (um1.find(ele.first) == um1.end() || ele.second > um1.at(ele.first)) {
                subset = false;
                break;
            }
        }

        if (subset) ps("Yes");
        else ps("No");
    }

    return 0;
}