#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/max-rectangle/1
 * Description:
 *  Given a binary matrix. 
 *  Find the maximum area of a rectangle formed only of 1s in the given matrix.
 *  Expected Time Complexity : O(n*m)
 *  Expected Auixiliary Space : O(m)
 * Resources:
 *  https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
 *  https://leetcode.com/problems/maximal-square/solution/#
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

int maxHist(int row[], int n)
{
    stack<int> result;

    int top_val, max_area{0}, area{0};

    int i{0};
    while (i < n)
    {
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);

        else
        {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;

            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }

    while (!result.empty())
    {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);

        max_area = max(area, max_area);
    }
    
    return max_area;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t{0};
    si(t);

    while (t--)
    {
        int m{0}, n{0};
        si(m);
        si(n);

        int arr[m][n];
        fo(i, m)
        {
            fo(j, n)
            {
                si(arr[i][j]);
            }
        }

        int result = maxHist(arr[0], n);

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 1)
                {
                    arr[i][j] += arr[i - 1][j];
                }
            }
            result = max(result, maxHist(arr[i], n));
        }

        ps(result);
    }

    return 0;
}