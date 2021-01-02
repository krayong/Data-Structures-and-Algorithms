#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1
 * Description:
 *  Given a N x N matrix, where every row and column is sorted in non-decreasing order. 
 *  Find the kth smallest element in the matrix.
 *  Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(N)
 * Resources:
 *  https://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array-set-1/
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

typedef pair<int, pair<int, int>> HeapNode;

void swap (HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify (HeapNode arr[], int pos, int size)
{
    int left = pos * 2 + 1;
    int right = pos * 2 + 2;
    int smallest = pos;

    if (left < size && arr[left].first < arr[smallest].first) smallest = left;
    if (right < size && arr[right].first < arr[smallest].first) smallest = right;

    if (smallest != pos) {
        swap(&arr[smallest], &arr[pos]);
        minHeapify(arr, smallest, size);
    }
}

void buildHeap (HeapNode arr[], int size)
{
    for (int i = (size - 1) / 2; i >= 0; i--) 
        minHeapify(arr, i, size);
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
        int arr[n][n];
        fo(i, n) fo(j, n) si(arr[i][j]);
        int k;
        si(k);

        HeapNode heap[n];
        fo(i, n) heap[i] = mp(arr[0][i], mp(0, i));
        buildHeap(heap, n);

        HeapNode kth;
        fo(i, k)
        {
            kth = heap[0];
            int next = (kth.second.first < n - 1) ? arr[kth.second.first + 1][kth.second.second] : INT_MAX;
            heap[0] = mp(next, mp(kth.second.first + 1, kth.second.second));
            minHeapify(heap, 0, n);
        }

        ps(kth.first);
    }

    return 0;
}