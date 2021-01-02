#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/rearrange-characters/0
 * Description:
    Given a string S with repeated characters (only lowercase). 
    The task is to rearrange characters in a string such that no two adjacent characters are same.
 * Resources:
 *  https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/
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

struct compare_keys
{
    constexpr bool operator()(pair<char, int> const& p1, pair<char, int> const& p2) const noexcept
    {
        return p1.s < p2.s;
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t{0};
    si(t);

    while (t--)
    {
        string str;
        ss(str);

        int count[26] = {0};
        for (int i = 0; i < str.length(); i++)
            count[str[i] - 'a']++;

        priority_queue<pair<char, int>, vector<pair<char, int>>, compare_keys> pq;
        for (char c = 'a'; c <= 'z'; c++)
            if (count[c - 'a'] > 0)
                pq.push(mp(c, count[c - 'a']));

        string result = "";

        pair<char, int> prev = mp('#', -1);

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            result += curr.first;

            if (prev.second > 0)
                pq.push(prev);

            curr.second--;
            prev = curr;
        }

        if (str.length() != result.length())
            cout << "Invalid" << "\n";
        else
            cout << result << "\n";
    }

    return 0;
}