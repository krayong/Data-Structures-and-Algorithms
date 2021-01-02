#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                        Boyer Moore Voting Algorithm      
 * Link : https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1
 * Description:
    Given an array A of N elements. Find the majority element in the array. 
    A majority element in an array A of size N is an element 
    that appears more than N/2 times in the array.
 * Resources:
 *  https://www.geeksforgeeks.org/majority-element/
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

        int count{1}, index{0};
        for (int i = 1; i < n; i++)
        {
            if (arr[index] == arr[i])
                ++count;
            else
                --count;

            if (count == 0)
            {
                index = i;
                count = 1;
            }
        }

        count = 0;
        fo(i, n) if (arr[i] == arr[index]) count++;

        if (count > n / 2)
            ps(arr[index]);
        else
            ps(-1);
    }

    return 0;
}