#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/
 * Description:
    Given a number of friends who have to give or take some amount of money from one another. 
    Design an algorithm by which the total cash flow among all the friends is minimized.

    Example:
    Following diagram shows input debts to be settled: https://media.geeksforgeeks.org/wp-content/cdn-uploads/cashFlow.png

    Above debts can be settled in following optimized way: https://media.geeksforgeeks.org/wp-content/cdn-uploads/cashFlow1.png
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
        int num_people, num_rels;
        si(num_people), si(num_rels);

        int amount_get[num_people] = {0};
        fo(i, 0, num_rels)
        {
            int from, to, amount;
            si(from), si(to), si(amount);

            --from, --to;

            amount_get[from] -= amount;
            amount_get[to] += amount;
        }

        vector<pair<int, pii>> result;

        while (true)
        {
            int max_to_be_given = max_element(amount_get, amount_get + num_people) - amount_get;
            int max_to_be_taken = min_element(amount_get, amount_get + num_people) - amount_get;

            if (amount_get[max_to_be_given] == 0 && amount_get[max_to_be_taken] == 0)
                break;

            int amount_exchanged = min(amount_get[max_to_be_given], abs(amount_get[max_to_be_taken]));
            amount_get[max_to_be_given] -= amount_exchanged;
            amount_get[max_to_be_taken] += amount_exchanged;

            result.pb(mp(amount_exchanged, mp(max_to_be_taken, max_to_be_given)));
        }

        for (auto ele : result)
            cout << "Person " << ele.se.fi + 1 << " owes Person "
                 << ele.se.se + 1 << " amount " << ele.fi << "\n";
    }

    return 0;
}