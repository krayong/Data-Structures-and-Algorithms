#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/stickler-theif/0
 * Description:
    Stickler the thief wants to loot money from a society having n houses in a single line. 
    He is a weird person and follows a certain rule when looting the houses. 
    According to the rule, he will never loot two consecutive houses. 
    At the same time, he wants to maximize the amount he loots. 
    The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. 
    He asks for your help to find the maximum money he can get if he strictly follows the rule. 
    Each house has a[i] amount of money present in it.
 * Resources:
 *  https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
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

        int incl = arr[0];
        int excl = 0;
        for(int i = 1; i < n; i++)
        {
            int temp = max(incl, excl);
            incl = excl + arr[i];
            excl = temp;
        }

        pi(max(incl, excl));
    }

    return 0;
}