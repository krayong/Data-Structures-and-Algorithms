#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/union-of-two-arrays/0
 * Description:
    Given two arrays A and B of size N and M respectively. The task is to find union between these two arrays.
    Union of the two arrays can be defined as the set containing distinct elements from both the arrays. 
    If there are repetitions, then only one occurrence of element should be printed in union.

    Input:
    The first line of input contains an integer T denoting the number of test cases. 
    Then T test cases follow. Each test case consist of three lines. 
    The first line of each test case contains two space separated integers N and M, 
    where N is the size of array A and M is the size of array B. 
    The second line of each test case contains N space separated integers denoting elements of array A. 
    The third line of each test case contains M space separated integers denoting elements of array B.

    Output:
    Correspoding to each test case, print the count of union elements of the two arrays.

    Expected Time Complexity: O(N + M).
    Expected Auxiliary Space: O(N + M). 
 * 
*************************************************************************************************************/

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define ss(s) getline(cin, s)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ps(s) cout << s << "\n";
#define fo(i, n) for (i = 0; i < n; i++)
// #define fo(i, k, n) for (i = k; k < n ? i < n : i >= n; k < n ? i++ : i--)
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
        int n{0}, m{0};
        si(n);
        si(m);
        int a[n], b[m];
        unordered_map<int, int> um;

        int i;

        fo(i, n) {
            si(a[i]);
            if (present(um, a[i])) um.at(a[i])++; 
            else um.insert(mp(a[i], 0));
        }

        fo(i, m)
        {
            si(b[i]);
            if (present(um, b[i])) um.at(b[i])++;
            else um.insert(mp(b[i], 0));
        }

        vi unionres, intersectionres;
        for (auto i: um) {
            unionres.pb(i.f);
            if (i.s > 1) intersectionres.pb(i.f);
        }

        ps(unionres.size()); 
    }

    return 0;
}