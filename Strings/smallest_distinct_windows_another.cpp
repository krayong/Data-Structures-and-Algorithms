#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
 * Description:
    Given two strings, find the smallest window in the first string 
    consisting of all the characters of the second string.
 * Resources:
 *  https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
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

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t{0};
    si(t);

    while (t--)
    {
        string parent, child;
        ss(parent);
        ss(child);

        int hash_parent[256] = {0};
        int hash_child[256] = {0};
        for (char c : child)
            hash_child[c]++;

        int start_index{-1}, min_length{INT_MAX};
        int start{0}, count{0};

        for (int i = 0; i < parent.length(); i++)
        {
            hash_parent[parent[i]]++;
            if (hash_child[parent[i]] != 0 && hash_child[parent[i]] <= hash_parent[parent[i]])
                count++;

            if (count == child.length())
            {
                while (hash_parent[parent[start]] > hash_child[parent[start]] || hash_child[parent[start]] == 0)
                {
                    if (hash_parent[parent[start]] > hash_child[parent[start]])
                        hash_parent[parent[start]]--;
                    start++;
                }

                int window = i - start + 1;
                if (window < min_length)
                {
                    start_index = i;
                    min_length = window;
                }
            }
        }

        if (start_index == -1)
            cout << "-1\n";
        else
            cout << parent.substr(start_index, min_length) << "\n";
    }

    return 0;
}