#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/maximum-product-subset-array/
 * Description:
    Given an array a, we have to find maximum product possible with the subset of 
    elements present in the array. The maximum product can be single element also.
    
    Examples: 

    Input: a[] = { -1, -1, -2, 4, 3 }
    Output: 24
    Explanation : Maximum product will be ( -2 * -1 * 4 * 3 ) = 24

    Input: a[] = { -1, 0 }
    Output: 0
    Explanation: 0(single element) is maximum product possible
    
    Input: a[] = { 0, 0, 0 }
    Output: 0
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

ll max_product_subset(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    ll product = 1;
    int num_neg = 0, num_zero = 0;
    int min_neg = INT_MIN;

    fo(i, 0, n)
    {
        if (arr[i] == 0)
        {
            ++num_zero;
            continue;
        }
        else if (arr[i] < 0)
        {
            ++num_neg;
            min_neg = max(min_neg, arr[i]);
        }

        product *= arr[i];
    }

    if (num_zero == n || (num_neg == 1 && num_zero + num_neg == n))
        return 0;
    else if (num_neg % 2 == 1)
        product /= min_neg;

    return product;
}

int main()
{
    fastio;
    randomize;

    int t;
    si(t);

    while (t--)
    {
        int n;
        si(n);

        int arr[n];
        fo(i, 0, n) si(arr[i]);

        cout << "Maximum product of subset of the array is: "
             << max_product_subset(arr, n) << "\n";
    }

    return 0;
}