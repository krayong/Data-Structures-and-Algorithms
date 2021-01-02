#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://leetcode.com/problems/search-in-rotated-sorted-array/
 * Description:
    You are given an integer array nums sorted in ascending order, and an integer target.
    Suppose that nums is rotated at some pivot unknown to you beforehand 
    (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

    If target is found in the array return its index, otherwise, return -1.
 * Resources:
 *  https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
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

int search(int arr[], int l, int h, int key)
{
    if (l > h)
        return -1;

    int mid = l + (h - l) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[l] <= arr[mid])
    {
        if (arr[l] <= key && arr[mid] > key)
            return search(arr, l, mid - 1, key);
        else
            return search(arr, mid + 1, h, key);
    }
    else
    {
        if (arr[mid] < key && arr[h] >= key)
            return search(arr, mid + 1, h, key);
        else
            return search(arr, l, mid - 1, key);
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t{0};
    si(t);

    while (t--)
    {
        int n{0}, key{0};
        si(n);
        si(key);
        int arr[n];
        fo(i, n) si(arr[i]);

        ps(search(arr, 0, n - 1, key));
    }

    return 0;
}