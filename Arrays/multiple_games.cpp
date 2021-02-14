#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.codechef.com/FEB21C/problems/MULGAME
 * Description:
    You are given a strictly increasing sequence of positive integers A1,A2,…,AN. 
    It is also guaranteed that for each valid i, Ai+A1≥Ai+1.

    Alice and Bob want to play Q independent games using this sequence. 
    Before they play these games, Alice should choose a positive integer G 
    between 1 and M (inclusive). The rules of each game are as follows:

    There is a set S of positive integers representing allowed moves in this game. 
    For each valid i, in the i-th game, this set is S={ALi,ALi+1,…,ARi} 
    (in other words, given by a contiguous subsequence of A).
    The game is played with a single pile. Let's denote the number of objects in 
    this pile by P. At the beginning of the game, P=G. In other words, Alice and Bob 
    play all the games with the same initial number of objects that Alice chooses.
    The players alternate turns; Alice plays first.
    In each turn, the current player must choose a positive integer b from the set S 
    such that b≤P and remove b objects from the pile, i.e. change P to P−b.
    When the current player cannot choose any such integer b, this player loses this game.
    Both players play optimally. You need to find the maximum number of games 
    Alice can win if she chooses G optimally.

    Input:
    The first line of the input contains a single integer T denoting the number of test cases. 
    The description of T test cases follows.
    The first line of each test case contains three space-separated integers N, Q and M.
    The second line contains N space-separated integers A1,A2,…,AN.
    Q lines follow. For each valid i, the i-th of these lines contains two space-separated integers Li and Ri.
    Output:
    For each test case, print a single line containing one integer ― the maximum number of games Alice can win.

    Constraints
    1≤T≤50
    1≤N,Q,M≤2⋅10^5
    1≤Ai≤10^8 for each valid i
    Ai+A1≥Ai+1>Ai for each valid i
    1≤Li≤Ri≤N for each valid i
    the sum of N over all test cases does not exceed 2⋅10^5
    the sum of Q over all test cases does not exceed 2⋅10^5
    the sum of M over all test cases does not exceed 2⋅10^5

    Example Input:
    1
    3 2 10
    2 3 4
    1 2
    2 3
    Example Output:
    2
    Explanation:
    Example case 1: The set of allowed moves in the first game is S={2,3} and in the second game, 
    it is S={3,4}. If Alice chooses G=3, she can win both games.
 * Resources:
 *  https://www.codechef.com/FEB21C/status/MULGAME?sort_by=All&sorting_order=asc&language=44&status=15&handle=&Submit=GO
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

struct hash_pair
{
    size_t operator()(const pii &p) const
    {
        auto hash1 = hash<int>{}(p.fi);
        auto hash2 = hash<int>{}(p.se);
        return hash<size_t>{}(hash1 + hash2);
    }
};

int main()
{
    // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t;
    si(t);

    while (t--)
    {
        int n, q, m;

        si(n);
        si(q);
        si(m);

        int arr[n];
        fo(i, 0, n) si(arr[i]);

        int freq[1000001] = {0};
        int res[m + 1] = {0};

        unordered_map<pii, int, hash_pair> um;
        while (q--)
        {
            int l, r;
            si(l);
            si(r);
            l--, r--;

            if (arr[l] > m)
                continue;

            if (arr[r] <= m)
                um[{arr[l], arr[r]}]++;

            freq[arr[l]]++, freq[m + 1]--;
        }

        for (auto ele : um)
        {
            int ff = ele.fi.fi, fs = ele.fi.se, s = ele.se;

            freq[fs + ff] -= s, freq[fs + 2 * ff] += s;

            int ctr = fs + 2 * ff;
            while (ctr + fs <= m)
            {
                ctr += fs;
                freq[ctr] -= s, freq[ctr + ff] += s;
                ctr += ff;
            }
        }

        fo(i, 1, m + 1) freq[i] += freq[i - 1];

        pi(*max_element(freq, freq + m + 1));
    }

    return 0;
}