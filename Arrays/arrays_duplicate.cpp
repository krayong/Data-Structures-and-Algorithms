#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                     Floyd's Circle Finding Algo (Tortoise and Hare)  
 * Link : https://leetcode.com/problems/find-the-duplicate-number/
 * Description:
    Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
    There is only one duplicate number in nums, return this duplicate number.

 * Resources:
    https://leetcode.com/problems/find-the-duplicate-number/solution/

    So, let us say, the straight path before the cycle in the linked list is of length : x
    the place where slow and fast meet is y distance from the start of the cycle
    there are z steps left to reach the start of the cycle again from the meeting place

    slow pointer : travels x + y distance to meet the fast pointer

    fast pointer :  travels (x + y + (z + y)) distance to meet the slow pointer 
    [reason : (x + y) to reach the meeting place, 
    but it again goes around the loop and meets it on its way back, so (z + y) steps are needed]

    But the fast pointer travels at speed 2 times that of slow pointer
    So, 2(x + y) = (x + 2y + z) => x = z

    This is an extremely powerful result, which means that the distance between the start of the linked list and the start of the cycle, 
    x is equal to the distance between the start of the cycle and the meeting point, z.

    So, if slow walks at a step of 1 each time from the head of the list, 
    and if fast walks at a pace of 1 step each time. They are to meet at the start of the cycle, 
    because slow will travel x steps and fast will travel z steps.
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
        int arr[n + 1];
        fo(i, n + 1) si(arr[i]);

        int tortoise{arr[0]}, hare{arr[0]};

        do
        {
            tortoise = arr[tortoise];
            hare = arr[arr[hare]];
        } while (hare != tortoise);

        tortoise = arr[0];
        while (tortoise != hare)
        {
            tortoise = arr[tortoise];
            hare = arr[hare];
        }

        ps(hare);
    }

    return 0;
}