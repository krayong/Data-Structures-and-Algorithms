#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://leetcode.com/problems/next-permutation/
 * Description:
    Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
    If such an arrangement is not possible, it must rearrange it as the lowest possible order 
    (i.e., sorted in ascending order).
    The replacement must be in place and use only constant extra memory.

    Example 1:
    Input: nums = [1,2,3]
    Output: [1,3,2]

    Example 2:
    Input: nums = [3,2,1]
    Output: [1,2,3]

    Example 3:
    Input: nums = [1,1,5]
    Output: [1,5,1]

    Example 4:
    Input: nums = [1]
    Output: [1]

 * Resources:
    https://leetcode.com/problems/next-permutation/solution/
    https://leetcode.com/problems/next-permutation/discuss/13867/C%2B%2B-from-Wikipedia
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
        int n{0};
        si(n);
        int arr[n];
        fo(i, n) si(arr[i]);

        int k{0}, l{0};
        for (k = n - 2; k >= 0; k--)
            if (arr[k] < arr[k + 1]) 
                break;

        if (k < 0) reverse(arr, arr + n);
        else 
        {
            for (l = n - 1; l > k; l--)
                if (arr[l] > arr[k])
                    break;

            swap(arr[l], arr[k]);
            reverse(arr + k + 1, arr + n);
        }

        fo(i, n) cout << arr[i] << " ";
        cout << "\n";
    }

    return 0;
}