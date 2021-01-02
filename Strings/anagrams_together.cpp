#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/print-anagrams-together/1
 * Description:
    Given an array of strings, return all groups of strings that are anagrams. 
    The groups must be created in order of their appearance in the original array. 
    Look at the sample case for clarification.

    Input:
    N = 5
    words[] = {act,god,cat,dog,tac}
    Output: 
    god dog
    act cat tac
    Explanation: There are 2 groups of
    anagrams god, dog make group 1.
    act, cat, tac make group 2. 
 * Resources:
 *  https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together-using-stl/
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

void print_anagrams(const vector<vs> &strings_vector)
{
    for (auto strings : strings_vector)
    {
        for (auto str : strings)
            cout << str << ", ";
        cout << "\n";
    }
}

vector<vs> get_anargrams(const vs &strings)
{
    map<map<char, int>, vs> um;
    for (string str : strings)
    {
        map<char, int> temp_map;
        for (char c : str)
            temp_map[c]++;

        if (um.find(temp_map) == um.end())
        {
            vs temp_vs;
            um.insert(mp(temp_map, temp_vs));
        }

        um.at(temp_map).pb(str);
    }

    vector<vs> strings_vector;
    for (auto m : um)
        strings_vector.pb(m.second);

    return strings_vector;
}

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

        vs strings(n);
        fo(i, n) ss(strings[i]);

        print_anagrams(get_anargrams(strings));
    }

    return 0;
}