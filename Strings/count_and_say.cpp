#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://leetcode.com/problems/count-and-say/
 * Description:
    The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
    countAndSay(1) = "1"
    countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), 
    which is then converted into a different digit string.
    To determine how you "say" a digit string, 
    split it into the minimal number of groups so that each group is a contiguous section all of the same character. 
    Then for each group, say the number of characters, then say the character. 
    To convert the saying into a digit string, replace the counts with a number and concatenate every saying.
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

string countAndSay(int n)
{
    string result = to_string(1);
    for (int i{1}; i < n; i++)
    {
        string temp = result;
        result = "";
        int last{0}, count{0};
        int len = temp.length();
        while (len--)
        {
            int num = (temp.at(temp.length() - 1)) - '0';
            temp = temp.substr(0, temp.length() - 1);
            if (last != 0)
            {
                if (last == num)
                {
                    count++;
                }
                else
                {
                    result = to_string(count) + to_string(last) + result;
                    count = 1;
                    last = num;
                }
            }
            else
            {
                count++;
                last = num;
            }
        }
        result = to_string(count) + to_string(last) + result;
    }
    return result;
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

        ps(countAndSay(n));
    }

    return 0;
}