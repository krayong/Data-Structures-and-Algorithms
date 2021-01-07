#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.spoj.com/problems/ANARC05B/
 * Description:
    Two ﬁnite, strictly increasing, integer sequences are given. 
    Any common integer between the two sequences constitute an intersection point. 
    Take for example the following two sequences where intersection points are
    7, 25, 55, 57

    First= 3 5 7 9 20 25 30 40 55 56 57 60 62
    Second= 1 4 7 11 14 25 44 47 55 57 100

    You can "walk" over these two sequences in the following way:

    You may start at the beginning of any of the two sequences. Now start moving forward.
    At each intersection point, you have the choice of either continuing with the same sequence 
    you’re currently on, or switching to the other sequence.
    The objective is ﬁnding a path that produces the maximum sum of data you walked over. 
    In the above example, the largest possible sum is 450, which is the result of 
    adding 3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, and 62

    Input
    Your program will be tested on a number of test cases. 
    Each test case will be speciﬁed on two separate lines. 
    Each line denotes a sequence and is speciﬁed using the following format:
    n v1 v2 ... vn
    where n is the length of the sequence and vi is the ith element in that sequence. 
    Each sequence will have at least one element but no more than 10,000. 
    All elements are between -10,000 and 10,000 (inclusive).
    The last line of the input includes a single zero, which is not part of the test cases.

    Output
    For each test case, write on a separate line, the largest possible sum that can be produced.

    Example:
    Input:
    13 3 5 7 9 20 25 30 40 55 56 57 60 62
    11 1 4 7 11 14 25 44 47 55 57 100
    4 -5 100 1000 1005
    3 -12 1000 1001
    0
    Output:
    450
    2100
 * Resources:
 *  https://www.youtube.com/watch?v=w-6YHcGmSxM&ab_channel=CodeLibrary
 * 
*************************************************************************************************************/

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define ss(s) getline(cin, s)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ps(s) cout << s << "\n"
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define rof(i, k, n) for (ll i = k; i >= n; i--)
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

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t{0};
    si(t);

    while (t--)
    {
        int n1{0};
        si(n1);

        int arr1[n1] = {0};
        fo(i, 0, n1) si(arr1[i]);

        int n2{0};
        si(n2);

        int arr2[n2] = {0};
        fo(i, 0, n2) si(arr2[i]);

        int sum{0}, i{0}, j{0};
        int sum1{0}, sum2{0};

        while (i < n1 && j < n2)
        {
            if (arr1[i] == arr2[j])
            {
                sum += max(sum1, sum2) + arr1[i];
                sum1 = sum2 = 0;
                ++i;
                ++j;
            }
            else if (arr1[i] < arr2[j])
            {
                sum1 += arr1[i];
                ++i;
            }
            else
            {
                sum2 += arr2[j];
                ++j;
            }
        }

        while (i < n1)
        {
            sum1 += arr1[i];
            ++i;
        }
        
        while (j < n2)
        {
            sum2 += arr2[j];
            ++j;
        }

        sum += max(sum1, sum2);

        pi(sum);
    }

    return 0;
}