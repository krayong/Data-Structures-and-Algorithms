#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/
 * Description:
    Given an array of N integers, and an integer K, 
    find the number of pairs of elements in the array whose sum is equal to K.
    
    Input: N = 4, K = 6, arr[] = {1, 5, 7, 1}
    Output: 2
    Explanation: arr[0] + arr[1] = 1 + 5 = 6 and arr[1] + arr[3] = 5 + 1 = 6.

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(N)

 * Resources:
    https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#editorial
    https://ide.geeksforgeeks.org/GALsuhTN8D
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
        unordered_map<int, int> m;

        int n{0}; si(n);
        ll k{0}; sll(k);
        int arr[n];
        fo(i, n) 
        {
            si(arr[i]);
            m[arr[i]]++;
        }

        int count{0};
        fo(i, n)
        {
            int x = k - arr[i];
            if(m.find(arr[i]) != m.end()) 
            {
                count += m[x];
                m[arr[i]]--;
        
                if (x == arr[i]) count--;
            }
        }

        ps(count);
    }

    return 0;
}