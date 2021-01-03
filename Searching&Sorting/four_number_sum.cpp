#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1
 * Description:
    Given an array of integers and another number. 
    Find all the unique quadruple from the given array that sums up to the given number.
 * Resources:
 *  https://www.geeksforgeeks.org/find-four-numbers-with-sum-equal-to-given-sum/
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

// Time Complexity: O(n^3) as three loops
// Space Complexity: O(1) as res contains result
vvi four_sum_n3(vi nums, int k)
{
    vvi res;
    int n{nums.size()};
    for (int i{0}; i < n - 3; i++)
    {
        for (int j{i + 1}; j < n - 2; j++)
        {
            int l{j + 1}, r{n - 1};
            while (l < r)
            {
                int sum{nums.at(i) + nums.at(j) + nums.at(l) + nums.at(r)};
                if (sum == k)
                {
                    res.pb(vector{nums.at(i), nums.at(j), nums.at(l), nums.at(r)});
                    ++l;
                    --r;
                }
                else if (sum < k)
                    ++l;
                else
                    --r;
            }
        }
    }

    // to remove duplicates
    sortall(res);
    res.erase(unique(all(res)), res.end());
    return res;
}

// Time Complexity: O(n^2) considering search in Map to be O(1) 
// Space Complexity: O(n^2) for map(n * (n - 1) / 2)
vvi four_sum_n2(vi nums, int k)
{
    unordered_map<int, pii> um;
    int n{nums.size()};
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            um.insert(mp(nums.at(i) + nums.at(j), mp(i, j)));

    vvi res;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum{nums.at(i) + nums.at(j)};
            if (um.find(k - sum) != um.end())
            {
                pii other = um.at(k - sum);
                if (other.fi != i && other.fi != j && other.se != i && other.se != j)
                    res.pb(vector{nums.at(i), nums.at(j), other.fi, other.se});
            }
        }
    }

    // to remove duplicates
    sortall(res);
    res.erase(unique(all(res)), res.end());
    return res;
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

        vi nums(n);
        fo(i, n)
        {
            int temp{0};
            si(temp);
            nums.pb(temp);
        }

        int k{0};
        si(k);

        sortall(nums);

        vvi res = four_sum_n3(nums, k);
        fo(i, res.size())
        {
            fo(j, res.at(i).size()) cout << res.at(i).at(j) << " ";
            cout << "\n";
        }

        res = four_sum_n2(nums, k);
        fo(i, res.size())
        {
            fo(j, res.at(i).size()) cout << res.at(i).at(j) << " ";
            cout << "\n";
        }
    }

    return 0;
}