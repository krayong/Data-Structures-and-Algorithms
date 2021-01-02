#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
 * Description:
    Given an array of integers where each element represents the max number of steps that can be made forward from that element. 
    The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). 
    If an element is 0, then cannot move through that element.

    Input: 
    The first line contains an integer T, depicting total number of test cases.  
    Then following T lines contains a number n denoting the size of the array. 
    Next line contains the sequence of integers a1, a2, ..., an.

    Output:
    For each testcase, in a new line, print the minimum number of jumps. 
    If answer is not possible print "-1"(without quotes).
 * Resources:
    https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
    https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/
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

// returns minimum number of jumps to reach arr[n-1] from arr[0]
int minJumps(int arr[], int n)
{

    // the number of jumps needed to reach the starting index is 0
    if (n <= 1)
        return 0;

    // return -1 if not possible to jump
    if (arr[0] == 0)
        return -1;

    // initialization stores all time the maximal reachable index in the array.
    int maxReach = arr[0];

    // stores the number of steps we can still take
    int step = arr[0];

    // stores the number of jumps necessary to reach that maximal reachable position.
    int jump = 1;

    // start traversing array
    for (int i = 1; i < n; i++)
    {
        // check if we have reached the end of the array
        if (i == n - 1)
            return jump;

        // updating maxReach
        maxReach = max(maxReach, i + arr[i]);

        // we use a step to get to the current index
        step--;

        // if no further steps left
        if (step == 0)
        {
            // we must have used a jump
            jump++;

            // check if the current index/position or lesser index is the maximum reach point from the previous indexes
            if (i >= maxReach)
                return -1;

            // re-initialize the steps to the amount of steps to reach maxReach from position i.
            step = maxReach - i;
        }
    }

    return -1;
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
        int arr[n];
        fo(i, n) si(arr[i]);

        ps(minJumps(arr, n));
    }

    return 0;
}