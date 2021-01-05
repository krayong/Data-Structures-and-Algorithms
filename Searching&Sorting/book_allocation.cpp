#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
 * Description:
    You are given N number of books. Every ith book has A[i] number of pages. 
    You have to allocate books to M number of students. 
    There can be many ways or permutations to do so. 
    In each permutation, one of the M students will be allocated the maximum number of pages. 
    Out of all these permutations, the task is to find that particular permutation 
    in which the maximum number of pages allocated to a student is minimum of those in 
    all the other permutations and print this minimum value. 

    Each book will be allocated to exactly one student. 
    Each student has to be allocated at least one book.

    Note: Return -1 if a valid assignment is not possible, 
    and allotment should be in contiguous order.

    Example 1:
    Input:
    N = 4
    A[] = {12,34,67,90}
    M = 2
    Output: 113
    Explanation: 
    Allocation can be done in following ways:
    {12} and {34, 67, 90} Maximum Pages = 191
    {12, 34} and {67, 90} Maximum Pages = 157
    {12, 34, 67} and {90}  Maximum Pages =113
    Therefore, the minimum of these cases is 
    113, which is selected as the output.

    Example 2:
    Input:
    N = 3
    A[] = {15,17,20}
    M = 2
    Output: 32
    Explanation: Allocation is done as {15,17} and {20}
    
    Expected Time Complexity : O(NlogN)
    Expected Auxilliary Space : O(1)
 * Resources:
 *  https://www.geeksforgeeks.org/allocate-minimum-number-pages/
 * 
*************************************************************************************************************/

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define ss(s) getline(cin, s)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ps(s) cout << s << "\n"
#define fo(i, k, n) for (int i = k; i < n; i++)
#define rof(i, k, n) for (int i = k; i > 0; i--)
#define ll long long
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

bool is_possible(int arr[], int n, int pages, int num_students)
{
    int students_required{1}, curr_sum{0};
    fo(i, 0, n)
    {
        if (arr[i] > pages)
            return false;
        if (curr_sum + arr[i] > pages)
        {
            ++students_required;
            curr_sum = arr[i];

            if (students_required > num_students)
                return false;
        }
        else
            curr_sum += arr[i];
    }
    return true;
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
        fo(i, 0, n) si(arr[i]);

        sort(arr, arr + n);

        int num_students{0};
        si(num_students);

        if (n < num_students)
            pi(-1);
        else
        {
            int lo{0}, hi{accumulate(arr, arr + n, 0)}, min_pages{INT_MAX};
            while (lo <= hi)
            {
                int mid{lo + (hi - lo) / 2};
                if (is_possible(arr, n, mid, num_students))
                {
                    min_pages = min(mid, min_pages);
                    hi = mid - 1;
                }
                else
                    lo = mid + 1;
            }

            pi(min_pages);
        }
    }

    return 0;
}