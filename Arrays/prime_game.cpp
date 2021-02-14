#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.codechef.com/FEB21C/problems/PRIGAME
 * Description:
    Chef and Divyam are playing a game with the following rules:

    First, an integer X! is written on a board.
    Chef and Divyam alternate turns; Chef plays first.
    In each move, the current player should choose a positive integer D which is divisible by up to Y 
    distinct primes and does not exceed the integer currently written on the board. Note that 1 is not a prime.
    D is then subtracted from the integer on the board, i.e. if the integer written on the board 
    before this move was A, it is erased and replaced by A−D.
    When one player writes 0 on the board, the game ends and this player wins.
    Given X and Y, determine the winner of the game.

    Input
    The first line of the input contains a single integer T denoting the number of test cases. 
    The description of T test cases follows.
    The first and only line of each test case contains two space-separated integers X and Y.
    Output
    For each test case, print a single line containing the string "Chef" if Chef wins the game or 
    "Divyam" if Divyam wins (without quotes).

    Constraints
    1≤T≤10^6
    1≤X,Y≤10^6

    Example Input:
    3
    1 2
    3 1
    2021 42

    Example Output:
    Chef
    Divyam 
    Divyam

    Explanation:

    Example case 1: Since D=1 is divisible by 0 primes, Chef will write 0 and win the game in the first move.

    Example case 2: Chef must choose D between 1 and 5 inclusive, since D=6 is divisible by 
    more than one prime. Then, Divyam can always choose 6−D, write 0 on the board and win the game.

 * Resources:
 *  https://www.codechef.com/FEB21C/status/PRIGAME?sort_by=All&sorting_order=asc&language=44&status=15&handle=&Submit=GO
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

#define MAX 1000000

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

void store_primes(ll num_primes_less[])
{
    ll num_primes = 0;

    fo(i, 0, MAX + 1)
    {
        if (is_prime(i))
            ++num_primes;

        num_primes_less[i] = num_primes;
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    ll num_primes_less[MAX + 1];
    store_primes(num_primes_less);

    int t;
    si(t);

    while (t--)
    {
        ll x, y;
        sll(x);
        sll(y);

        ll primes_less_than_x = num_primes_less[x];
        if (primes_less_than_x <= y)
            cout << "Chef\n";
        else
            cout << "Divyam\n";
    }

    return 0;
}