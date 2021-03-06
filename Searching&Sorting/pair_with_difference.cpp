#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/find-pair-given-difference/0
 * Description:
    Given an unsorted array arr[] and a number x. 
    You need to write a program to find if there exists a pair of elements in the array whose difference is x.
 * Resources:
 *  https://www.geeksforgeeks.org/find-a-pair-with-the-given-difference/
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

// Time Complexity: O(n) but Space Complexity: O(n)
bool sol1(int arr[], int n, int x)
{
    unordered_set<int> us;
    fo(i, n) us.insert(arr[i]);
    //            a - b = x where arr[i] = b           a - b = x where arr[i] = a
    fo(i, n) if ((us.find(arr[i] + x) != us.end()) || (us.find(arr[i] - x) != us.end())) return true;

    return false;
}

// Space Complexity: O(1) but Time Complexity: O(nlogn)
bool sol2(int arr[6], int n, int x)
{
    sort(arr, arr + n);

    int i{0}, j{1};
    while (i < n && j < n)
    {
        if (i != j && arr[j] - arr[i] == x)
            return true;
        else if (arr[j] - arr[i] < x)
            j++;
        else
            i++;
    }

    return false;
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

        int arr[n] = {0};
        fo(i, n) si(arr[i]);

        int x{0};
        si(x);

        ps(sol1(arr, n, x));
        ps(sol2(arr, n, x));
    }

    return 0;
}