#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.codechef.com/FEB21C/problems/TEAMNAME
 * Description:
    Сhef has assembled a football team! Now he needs to choose a name for his team. 
    There are N words in English that Chef considers funny. These words are s1,s2,…,sN.

    Chef thinks that a good team name should consist of two words such that they are not funny, 
    but if we swap the first letters in them, the resulting words are funny. 
    Note that under the given constraints, this means that a word is a non-empty string 
    containing only lowercase English letters.

    Can you tell Chef how many good team names there are?

    Input:
    The first line of the input contains a single integer T denoting the number of test cases. 
    The description of T test cases follows.
    The first line of each test case contains a single integer N.
    The second line contains N space-separated strings s1,s2,…,sN.

    Output:
    For each test case, print a single line containing one integer — 
    the number of ways to choose a good team name.

    Constraints:
    1≤T≤100
    2≤N≤2⋅104
    2≤|si|≤20 for each valid i
    s1,s2,…,sN contain only lowercase English letters
    s1,s2,…,sN are pairwise distinct
    the sum of N over all test cases does not exceed 2⋅104

    Example Input:
    3
    2
    suf mas
    3
    good game guys
    4
    hell bell best test

    Example Output:
    2
    0
    2

    Explanation:
    Example case 1: The good team names are ("muf", "sas") and ("sas", "muf").

    Example case 2: There are no good team names because all funny words start with 'g'.

    Example case 3: The good team names are ("hest", "tell") and ("tell", "hest").
 * Resources:
 *  https://www.codechef.com/FEB21C/status/TEAMNAME?sort_by=All&sorting_order=asc&language=44&status=15&handle=&Submit=GO
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

int find_distinct(vector<char> &v1, vector<char> &v2)
{
    set<char> s(all(v1));
    s.insert(all(v2));

    return s.size();
}

int main()
{
    int t;
    si(t);

    while (t--)
    {
        int n;
        si(n);

        unordered_map<string, vector<char>> funny_names_map;
        fo(i, 0, n)
        {
            string temp;
            cin >> temp;

            funny_names_map[temp.substr(1)].pb(temp[0]);
        }

        vs funny_names_body;
        for (auto ele : funny_names_map)
            funny_names_body.pb(ele.fi);

        int team_names = 0;
        fo(i, 0, funny_names_map.size() - 1)
        {
            fo(j, i + 1, funny_names_map.size())
            {
                auto i_vec = funny_names_map[funny_names_body[i]];
                auto j_vec = funny_names_map[funny_names_body[j]];

                int total_distinct = find_distinct(i_vec, j_vec);
                team_names += 2 * (total_distinct - i_vec.size()) * (total_distinct - j_vec.size());
            }
        }

        cout << team_names << "\n";
    }

    return 0;
}