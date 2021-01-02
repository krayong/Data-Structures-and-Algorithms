#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/function-to-find-number-of-customers-who-could-not-get-a-computer/
 * Description:
    Write a function “runCustomerSimulation” that takes following two inputs
    a) An integer ‘n’: total number of computers in a cafe and a string:
    b) A sequence of uppercase letters ‘seq’: Letters in the sequence occur in pairs. 
    The first occurrence indicates the arrival of a customer; 
    the second indicates the departure of that same customer.

    A customer will be serviced if there is an unoccupied computer. 
    No letter will occur more than two times.
    Customers who leave without using a computer always depart before customers who are 
    currently using the computers. There are at most 20 computers per cafe.

    For each set of input the function should output a number telling how many customers, 
    if any walked away without using a computer. Return 0 if all the customers were able to use a computer.

    runCustomerSimulation (2, “ABBAJJKZKZ”) should return 0

    runCustomerSimulation (3, “GACCBDDBAGEE”) should return 1 as ‘D’ was not able to get any computer
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
        string str;
        ss(str);

        unordered_set<char> us;

        int num_left{0};
        for (char c : str)
        {
            if (us.find(c) == us.end())
            {
                if (us.size() >= n)
                    num_left++;
                us.insert(c);
            }
            else if (us.find(c) != us.end())
                us.erase(us.find(c));
        }

        ps(num_left);
    }

    return 0;
}