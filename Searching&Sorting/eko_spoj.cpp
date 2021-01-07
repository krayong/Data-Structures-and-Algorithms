#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.spoj.com/problems/EKO/
 * Description:
    Lumberjack Mirko needs to chop down M metres of wood. 
    It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire. 
    However, Mirko is only allowed to cut a single row of trees.

    Mirko's machine works as follows: 
    Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade to that height 
    and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). 
    Mirko then takes the parts that were cut off. For example, if the tree row contains trees with 
    heights of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres, 
    the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, 
    while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

    Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. 
    That's why he wants to set his sawblade as high as possible. 
    Help Mirko find the maximum integer height of the sawblade that still allows him 
    to cut off at least M metres of wood.

    Input
    The first line of input contains two space-separated positive integers, 
    N (the number of trees, 1 ≤ N ≤ 1 000 000) and M (Mirko‟s required wood amount, 1 ≤ M ≤ 2 000 000 000).
    The second line of input contains N space-separated positive integers less than 1 000 000 000, 
    the heights of each tree (in metres). The sum of all heights will exceed M, 
    thus Mirko will always be able to obtain the required amount of wood.

    Output
    The first and only line of output must contain the required height setting.

    Examples:

    Input:
    4 7
    20 15 10 17
    Output:
    15

    Input:
    5 20
    4 42 40 26 46
    Output:
    36
 * Resources:
 *  https://discuss.codechef.com/t/eko-spoj-https-www-spoj-com-problems-eko/73576/3
 *  Similar to : https://www.geeksforgeeks.org/allocate-minimum-number-pages/
 * 
*************************************************************************************************************/

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define ss(s) getline(cin, s)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ps(s) cout << s << "\n"
#define fo(i, k, n) for (int i = k; i < n; i++)
#define rof(i, k, n) for (int i = k; i > 0; i--)
#define ll long long
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

bool is_possible(int arr[], int num_trees, int height, int wood_required)
{
    int wood_cut{0};
    fo(i, 0, num_trees) if (arr[i] > height)
        wood_cut += arr[i] - height;

    return wood_cut >= wood_required;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t{0};
    si(t);

    while (t--)
    {
        int num_trees{0}, wood_required{0};
        si(num_trees);
        si(wood_required);

        int arr[num_trees] = {0};
        fo(i, 0, num_trees) si(arr[i]);

        sort(arr, arr + num_trees);

        int lo{0}, hi{*max_element(arr, arr + num_trees)}, max_height{-1};
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (is_possible(arr, num_trees, mid, wood_required))
            {
                max_height = max(mid, max_height);
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }

        pi(max_height);
    }

    return 0;
}