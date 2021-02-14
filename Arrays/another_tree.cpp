#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 *                                              
 * Link : https://www.codechef.com/FEB21C/problems/ATWNT
 * Description:
    You are given a rooted tree with N nodes (numbered 1 through N; node 1 is the root). 
    For each i (1≤i≤N−1), the parent of the node i+1 is pi.

    You need to answer Q queries. (Sounds quite familiar!) For each query, first, 
    W tasks are given to node V. These tasks are processed in the tree in the following way:

    When a node receives a tasks and it has no children, all a tasks are executed by this node.
    Otherwise, i.e. if the node has K>0 children, where K is a divisor of a, 
    then this node gives a/K of these tasks to each of its children. 
    This process is performed recursively by each child on the tasks it receives.
    Otherwise, i.e. if the node has K>0 children, but K is not a divisor of a, 
    all a tasks are ignored and none of this node's children receive any tasks.
    For each query, find the number of tasks that are not executed, i.e. end up ignored, 
    possibly after passing down the tree.

    Input:
    The first line of the input contains a single integer N.
    The second line contains N−1 space-separated integers p1,p2,…,pN−1.
    The third line contains a single integer Q.
    Q lines follow. Each of these lines contains two space-separated integers V and W describing a query.

    Output:
    For each query, print a single line containing one integer ― the number of tasks that are not executed.

    Constraints:
    1≤N,Q≤105
    1≤pi≤N for each valid i
    the graph described on the input is a tree
    1≤V≤N
    1≤W≤106

    Example Input:
    5
    1 1 2 2
    2
    1 10
    1 20
    
    Example Output:
    5
    0
 * Resources:
 *  https://www.codechef.com/FEB21C/status/ATWNT?sort_by=All&sorting_order=asc&language=44&status=15&handle=&Submit=GO
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

struct hash_pair
{
    size_t operator()(const pii &p) const
    {
        auto hash1 = hash<int>{}(p.fi);
        auto hash2 = hash<int>{}(p.se);
        return hash<size_t>{}(hash1 + hash2);
    }
};

unordered_map<int, vi> children;
unordered_map<pii, int, hash_pair> um;

int tasks_skipped(int node_num, int tasks)
{
    if (um.find(mp(node_num, tasks)) != um.end())
        return um.at(mp(node_num, tasks));

    if (!present(children, node_num))
    {
        um.insert(mp(mp(node_num, tasks), 0));
        return 0;
    }

    int children_count = children[node_num].size();

    if (tasks % children_count != 0)
    {
        um.insert(mp(mp(node_num, tasks), tasks));
        return tasks;
    }

    int total_tasks_skipped = 0;
    for (int child : children[node_num])
        total_tasks_skipped += tasks_skipped(child, tasks / children_count);

    um.insert(mp(mp(node_num, tasks), total_tasks_skipped));
    return total_tasks_skipped;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int n;
    si(n);

    fo(i, 1, n)
    {
        int temp;
        si(temp);
        children[temp].pb(i + 1);
    }

    int q;
    si(q);

    while (q--)
    {
        int v, w;
        si(v);
        si(w);

        cout << tasks_skipped(v, w) << "\n";
    }

    return 0;
}