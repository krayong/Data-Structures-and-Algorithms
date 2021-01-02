#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                          Dutch National Flag    
 * Link : https://practice.geeksforgeeks.org/problems/three-way-partitioning/1
 * Description:
    Given an array of size N and a range [a, b]. 
    The task is to partition the array around the range such that array is divided into three parts.
    1) All elements smaller than a come first.
    2) All elements in range a to b come next.
    3) All elements greater than b appear in the end.
    The individual elements of three sets can appear in any order. 
    You are required to return the modified array.

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(1)
 * Resources:
 *  https://www.geeksforgeeks.org/three-way-partitioning-of-an-array-around-a-given-range/
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

        int low{0}, high{0};
        si(low); si(high);

        int start{0}, end{n - 1};

        for(int i = 0; i <= end;) 
        {
            if (arr[i] < low) swap(arr[i++], arr[start++]);
            else if (arr[i] > high) swap(arr[i], arr[end--]);
            else i++;
        }
    }

    return 0;
}