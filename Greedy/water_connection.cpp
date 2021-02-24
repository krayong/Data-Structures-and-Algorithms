#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/water-connection-problem/1
 * Description:
    Every house in the colony has at most one pipe going into it and at most one pipe going out of it. 
    Tanks and taps are to be installed in a manner such that every house with one outgoing pipe 
    but no incoming pipe gets a tank installed on its roof and every house with only an incoming pipe 
    and no outgoing pipe gets a tap. Find the efficient way for the construction of the network of pipes.

    Input:
    The first line contains an integer T denoting the number of test cases. 
    For each test case, the first line contains two integer n & p denoting 
    the number of houses and number of pipes respectively. 
    Next, p lines contain 3 integer inputs a, b & d, d denoting 
    the diameter of the pipe from the house a to house b.  

    Output:
    For each test case, the output is the number of pairs of tanks and taps 
    installed i.e n followed by n lines that contain three integers: 
    house number of tank, house number of tap and the minimum diameter of pipe between them.  

    Constraints:
    1<=T<=50
    1<=n<=20
    1<=p<=50
    1<=a,b<=20
    1<=d<=100

    Example:

    Input:
    1
    9 6
    7 4 98
    5 9 72
    4 6 10
    2 8 22
    9 7 17
    3 1 66

    Output:
    3
    2 8 22
    3 1 66
    5 6 10

    Explanation:
    Connected components are 3->1, 5->9->7->4->6 and 2->8.
    Therefore, our answer is 3 followed by 2 8 22, 3 1 66, 5 6 10.
 * Resources:
 *  https://www.geeksforgeeks.org/water-connection-problem/
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

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int dfs(int idx, int &min_diam, int forward[], int backward[], int diams[])
{
    if (forward[idx] == 0) // has no outgoing pipe so can give water to the idx
        return idx;

    if (diams[idx] < min_diam)
        min_diam = diams[idx];

    return dfs(forward[idx], min_diam, forward, backward, diams);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t;
    si(t);

    while (t--)
    {
        int houses, pipes;
        si(houses), si(pipes);

        int forward[houses + 1] = {0}, backward[houses + 1] = {0}, diams[houses + 1] = {0};

        fo(i, 0, pipes)
        {
            int start, end, diam;
            si(start), si(end), si(diam);

            forward[start] = end;
            backward[end] = start;
            diams[start] = diam;
        }

        vector<pair<int, pii>> result;

        fo(i, 1, houses + 1)
        {
            if (backward[i] == 0 && forward[i] != 0) // no incoming pipe but has outgoing pipe
            {
                int min_diam = INT_MAX;
                int end = dfs(i, min_diam, forward, backward, diams);

                result.pb(mp(i, mp(end, min_diam)));
            }
        }

        cout << result.size() << "\n";
        for (auto ele : result)
            cout << ele.fi << " " << ele.se.fi << " " << ele.se.se << "\n";
    }

    return 0;
}