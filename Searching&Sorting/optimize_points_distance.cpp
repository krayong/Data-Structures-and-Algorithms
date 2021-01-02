#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.geeksforgeeks.org/optimum-location-point-minimize-total-distance/
 * Description:
    Given a set of points as and a line as ax+by+c = 0. 
    We need to find a point on given line for which sum of distances from given set of points is minimum.
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

struct line
{
    ll a, b, c;
    line(ll a, ll b, ll c) : a(a), b(b), c(c) {}
    double calc_y(double x)
    {
        return (-1) * (c + a * x) / b;
    }
};

double dist(double x, double y, pll p)
{
    return sqrt(pow(x - p.fi, 2) + pow(y - p.se, 2));
}

double compute_total_dist(vpll v, line l, double x)
{
    double total_dist = 0;
    double y = l.calc_y(x);

    for (pll p : v)
        total_dist += dist(x, y, p);

    return total_dist;
}

double min_dist(vpll v, line l)
{
    double low = 1e6, high = -1e6;

    double range = 1e-6;

    while ((high - low) > range)
    {
        double mid1 = low + (high - low) / 3.0;
        double mid2 = high - (high - low) / 3.0;

        double dist1 = compute_total_dist(v, l, mid1);
        double dist2 = compute_total_dist(v, l, mid2);

        if (dist1 < dist2)
            high = mid2;
        else
            low = mid1;
    }

    return compute_total_dist(v, l, low + (high - low) / 2);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t{0};
    si(t);

    while (t--)
    {
        ll n{0};
        sll(n);

        vpll v;
        fo(i, n)
        {
            ll temp1{0}, temp2{0};
            sll(temp1);
            sll(temp2);
            v.pb(mp(temp1, temp2));
        }

        ll a, b, c;
        sll(a);
        sll(b);
        sll(c);

        ps(min_dist(v, line(a, b, c)));
    }

    return 0;
}