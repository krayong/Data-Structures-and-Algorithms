#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/smallest-subset-sum-greater-elements/
 * Description:
    Given an array of non-negative integers. Our task is to find minimum number of elements 
    such that their sum should be greater than the sum of rest of the elements of the array.

    Examples :

    Input : arr[] = {3, 1, 7, 1}
    Output : 1
    Explanation:
    Smallest subset is {7}. Sum of this subset is greater than all other elements {3, 1, 1}

    Input : arr[] = {2, 1, 2}
    Output : 2
    Explanation:
    In this example one element is not enough. We can pick elements with 
    values 1, 2 or 2, 2. In any case, the minimum count is 2.
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
        int n;
        si(n);

        int arr[n];
        fo(i, 0, n) si(arr[i]);

        sort(arr, arr + n, greater<int>());

        int half_sum = accumulate(arr, arr + n, 0) / 2;

        int num_ele = 0, running_sum = 0;
        fo(i, 0, n / 2 + 1)
        {
            running_sum += arr[i];
            ++num_ele;

            if (running_sum > half_sum)
                break;
        }

        pi(num_ele);
    }

    return 0;
}