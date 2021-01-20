#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/minimum-swap-required-convert-binary-tree-binary-search-tree/
 * Description:
    Given the array representation of Complete Binary Tree i.e, if index i is the parent, 
    index 2*i + 1 is the left child and index 2*i + 2 is the right child. 
    The task is to find the minimum number of swap required to convert it into Binary Search Tree.

    Examples:  

    Input : arr[] = { 5, 6, 7, 8, 9, 10, 11 }
    Output : 3

    Input : arr[] = { 1, 2, 3 }
    Output : 1
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
#define ll long long
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define rof(i, k, n) for (ll i = k; i >= n; i--)
#define deb(x) cout << #x << "=" << x << "\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define set(x, i) memset(x, i, sizeof(x))
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

void inorder(int arr[], vi &v, int n, int idx)
{
    if (idx >= n)
        return;

    inorder(arr, v, n, 2 * idx + 1);
    v.pb(arr[idx]);
    inorder(arr, v, n, 2 * idx + 2);
}

int min_swaps(vi &v)
{
    vpii t(v.size());

    fo(i, 0, v.size())
        t[i] = mp(v[i], i);

    sortall(t);

    int ans = 0;
    fo(i, 0, t.size())
    {
        if (i == t[i].se)
            continue;
        
        swap(t[i].fi, t[t[i].se].fi);
        swap(t[i].se, t[t[i].se].se);

        if (i != t[i].se)
            --i;

        ++ans;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t;
    si(t);

    while (t--)
    {
        int n;
        si(n);

        int arr[n] = {0};
        fo(i, 0, n) si(arr[i]);

        vi v;
        inorder(arr, v, n, 0);

        cout << "Min swaps required: " << min_swaps(v) << "\n";
    }

    return 0;
}