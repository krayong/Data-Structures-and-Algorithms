#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/palindromic-array/0
 * Description:
    You are given an array A of size N. 
    Your task is to find the minimum number of operations needed to convert the given array to 'Palindromic Array'.
    Palindromic Array:
    [23,15,23] is a ‘Palindromic Array’ but [2,0,1] is not.
    The only allowed operation is that you can merge two adjacent elements in the array and replace them with their sum.
 * Resources:
 *  https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/
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
        int n{0};
        si(n);

        int arr[n];
        fo(i, n) si(arr[i]);

        int min_merges{0};

        for (int i = 0, j = n - 1; i <= j;)
        {
            if (arr[i] == arr[j])
            {
                i++;
                j--;
            }
            else if (arr[i] > arr[j])
            {
                j--;
                arr[j] += arr[j + 1];
                min_merges++;
            }
            else
            {
                i++;
                arr[i] += arr[i - 1];
                min_merges++;
            }
        }

        ps(min_merges);
    }

    return 0;
}