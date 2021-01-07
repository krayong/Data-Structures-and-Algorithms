#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.spoj.com/problems/PRATA/
 * Description:
    IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. 
    The subcommittee members are asked to go to food connection and get P(P<=1000) pratas 
    packed for the function. The stall has L cooks(L<=50) and each cook has a rank R(1<=R<=8). 
    A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 
    1 more prata in 3R minutes and so on(he can only cook a complete prata) 
    ( For example if a cook is ranked 2.. he will cook one prata in 2 minutes one more prata 
    in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas 
    in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). 
    The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.

    Input
    The first line tells the number of test cases. Each test case consist of 2 lines. 
    In the first line of the test case we have P the number of prata ordered. 
    In the next line the first integer denotes the number of cooks L 
    and L integers follow in the same line each denoting the rank of a cook.

    Output
    Print an integer which tells the number of minutes needed to get the order done.

    Example:
    Input:
    3
    10
    4 1 2 3 4
    8
    1 1
    8
    8 1 1 1 1 1 1 1 1
    Output:
    12
    36
    1
 * Resources:
 *  https://www.youtube.com/watch?v=-Nx1h54KzUQ&ab_channel=CodeLibrary
 * 
*************************************************************************************************************/

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define ss(s) getline(cin, s)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ps(s) cout << s << "\n"
#define fo(i, k, n) for (int i = k; i < n; i++)
#define rof(i, k, n) for (int i = k; i >= n; i--)
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

bool is_possible(int rank[], int cooks, int paras, int time_given)
{
    int num_paras{0};
    fo(i, 0, cooks)
    {
        int time_taken{rank[i]}, r_counter{2};
        while (time_taken <= time_given)
        {
            ++num_paras;
            time_taken += (rank[i] * r_counter);
            ++r_counter;
        }
        if (num_paras >= paras)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t{0};
    si(t);

    while (t--)
    {
        int paras{0}, cooks{0};
        si(paras);
        si(cooks);

        int rank[cooks] = {0};
        fo(i, 0, cooks) si(rank[i]);

        int lo{0}, hi{1e8}, min_time{INT_MAX};
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (is_possible(rank, cooks, paras, mid))
            {
                min_time = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        pi(min_time);
    }

    return 0;
}