#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together/0
 * Description:
    Given an array of n positive integers and a number k. 
    Find the minimum number of swaps required to bring all the numbers less than or equal to k together.
 * Resources:
 *  https://www.geeksforgeeks.org/minimum-swaps-required-bring-elements-less-equal-k-together/
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
        int n{0}, k{0};
        si(n);

        int arr[n];
        fo(i, n) si(arr[i]);

        si(k);

        int min_swaps{0};

        int count{0}, bad{0};
        fo(i, n) if (arr[i] <= k) count++;
        fo(i, count) if (arr[i] > k) bad++;

        for (int i = 0, j = count; j < n; i++, j++) 
        {
            if (arr[i] > k) bad--;
            if (arr[j] > k) bad++;

            min_swaps = min(min_swaps, bad);
        }

        ps(min_swaps);
    }

    return 0;
}