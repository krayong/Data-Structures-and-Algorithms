#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://leetcode.com/problems/search-a-2d-matrix/
 * Description:
    Write an efficient algorithm that searches for a value in an m x n matrix. 
    This matrix has the following properties:
    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.
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
        int r{0}, c{0};
        si(r);
        si(c);

        int arr[r][c];
        fo(i, r)
        {
            fo(j, c)
            {
                si(arr[i][j]);
            }
        }

        int num{0};
        si(num);

        bool present = false;

        if (!(arr[0][0] > num || arr[r - 1][c - 1] < num))
        {
            int greater_index{1};
            for (; greater_index < r; greater_index++)
            {
                if (arr[greater_index][0] == num)
                {
                    present = true;
                    break;
                }
                else if (arr[greater_index][0] > num)
                    break;
            }

            if (present)
                present = true;
            else
            {
                int row_to_be_searched = greater_index - 1;

                int low{0}, high{c - 1};

                while (low <= high)
                {
                    int mid = low + (high - low) / 2;
                    if (arr[row_to_be_searched][mid] == num)
                    {
                        present = true;
                        break;
                    }
                    else if (arr[row_to_be_searched][mid] > num)
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
            }
        }
        cout << boolalpha << present << "\n";
    }

    return 0;
}