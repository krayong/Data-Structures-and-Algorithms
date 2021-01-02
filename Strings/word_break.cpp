#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/word-break1352/1
 * Description:
    Given a string A and a dictionary of n words B, 
    find out if A can be segmented into a space-separated sequence of dictionary words. 

    Example 1:
    Input:
    n = 12
    B = { "i", "like", "sam", "sung", "samsung", "mobile",
    "ice","cream", "icecream", "man", "go", "mango" }
    A = "ilike"
    Output: 1
    Explanation:The string can be segmented as "i like".

    Example 2:
    Input:
    n = 12
    B = { "i", "like", "sam", "sung", "samsung", "mobile",
    "ice","cream", "icecream", "man", "go", "mango" }
    A = "ilikesamsung"
    Output: 1
    Explanation: The string can be segmented as 
    "i like samsung" or "i like sam sung".
    
    Expected time complexity: O(s2)
    Expected auxiliary space: O(s) , where s = length of string A
 * Resources:
 *  https://www.geeksforgeeks.org/word-break-problem-dp-32/
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

bool contains(string str, const vector<string> words)
{
    for (auto word : words)
    {
        if (word == str)
            return true;
    }
    return false;
}

bool wordBreak(string str, const vector<string> words)
{
    int n = str.size();

    if (n == 0)
        return true;

    // Create the DP table to store results of subroblems.
    // The value dp[i] will be true if str[0..i] can be
    // segmented into dictionary words, otherwise false.
    vector<bool> dp(n + 1, 0); // Initialize all values as false.

    // matched_index array represents the indexes for which dp[i] is true. 
    // Initially only -1 element is present in this array.
    vi matched_index;
    matched_index.pb(-1);

    for (int i = 0; i < n; i++)
    {
        int msize = matched_index.size();

        // Match value which tells that a substring matches with given words or not.
        bool match = false;

        // Check all the substring from the indexes matched earlier.
        // If any of that substring matches than make match value = true;
        for (int j = msize - 1; j >= 0; j--)
        {
            // sb is substring starting from matched_index[j]  + 1  and of length i - matched_index[j]
            string sb = str.substr(matched_index[j] + 1, i - matched_index[j]);

            if (contains(sb, words))
            {
                match = true;
                break;
            }
        }

        // If substring matches than do dp[i] = true and push that index in matched_index array.
        if (match)
        {
            dp[i] = true;
            matched_index.push_back(i);
        }
    }
    return dp[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    vector<string> words = {"mobile", "samsung", "sam", "sung",
                            "man", "mango", "icecream", "and",
                            "go", "i", "like", "ice", "cream"};

    wordBreak("ilikesamsung", words) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("iiiiiiii", words) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("", words) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("ilikelikeimangoiii", words) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("samsungandmango", words) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("samsungandmangok", words) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}