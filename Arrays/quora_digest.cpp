#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
                                        Digest Recommendation

    There’s a lot of content on Quora and we need a way of recommending the top stories for a user. Recommender
    systems drive many features at Quora, but in this problem we’ll focus on Digest recommendation. Quora Digests are
    emails which we send to users containing top recommended stories based on their interests.
    Note: This is a fictitious representation of our Digest recommender system.
    There are n stories (S1, . . . , Sn) and m users (U1, . . . , Um). Each story is created by a single user. 
    A user can follow both other users and other stories.
    The Digest recommendation score for story Sk to user Ui is defined as follows:

    If Ui created or follows Sk, the score is −1. Otherwise, the score is

    Sum(a(Ui, Uj ) × b(Uj , Sk)) for j in 1 to m where,

    a(Ui, Uj) =
    0 if i = j
    otherwise, 3 if Ui follows Uj
    otherwise, 2 if Ui follows stories created by Uj
    otherwise, 1 if Ui follows stories followed by Uj
    otherwise, 0

    b(Uj , Sk) =
    2, if Uj created Sk
    otherwise, 1 if Uj follows Sk
    otherwise, 0

    Given the stories, users, and their associations, find the top three recommended Digest stories for each user.
    
    Input:
    Your program will receive input from standard input.
    The first line contains two space-separated positive integers n and m, 
    representing the number of stories and the number of users.
    The following n lines each contain a single integer. 
    The k-th line contains an integer j indicating that Uj created Sk.
    After that, there will be two integers p and q, 
    representing the number of follows between users and the number of story follows.
    The next p lines each contain two integers i and j representing that user Ui follows user Uj .
    The final q lines each contain two integers i and k representing that user Ui follows story Sk.

    Output:
    Print m lines. The i-th line should contain three integers representing the recommended stories for Ui
    To select the stories to output, sort all the stories in non-increasing order 
    by recommendation score, and in increasing order by story
    index among stories with the same score. Then, print the indexes of the first 3 stories in that order.

    Constraints:
    5 ≤ n, m ≤ 200
    0 ≤ p ≤ n
    2 − n
    0 ≤ q ≤ nm
    It is guaranteed that there will be at least 3 stories to recommend for each user.
    There will be no duplication on follow relations.
    When Ui created Sk, it is guaranteed that Ui does not follow Sk.

    Example:

    Input:
    7 5
    1
    1
    2
    3
    4
    5
    5
    2 4
    1 2
    4 5
    1 7
    5 2
    3 3
    4 1

    Output:
    3 6 4
    1 2 4
    1 2 5
    7 2 6
    1 3 4
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

bool check_any_matching(vi &v1, vi &v2)
{
    return find_first_of(all(v1), all(v2)) != v1.end();
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int n, m;
    si(n);
    si(m);

    unordered_map<int, vi> story_creations;
    fo(i, 0, n)
    {
        int temp;
        si(temp);
        story_creations[temp].pb(i + 1);
    }

    int p, q;
    si(p);
    si(q);

    unordered_map<int, vi> user_follows;
    fo(i, 0, p)
    {
        int temp1, temp2;
        si(temp1);
        si(temp2);
        user_follows[temp1].pb(temp2);
    }

    unordered_map<int, vi> story_follows;
    fo(i, 0, q)
    {
        int temp1, temp2;
        si(temp1);
        si(temp2);
        story_follows[temp1].pb(temp2);
    }

    vector<vpii> recommendations;
    fo(i, 1, m + 1)
    {
        auto i_created_stories = story_creations.find(i);
        auto i_followed_stories = story_follows.find(i);
        auto i_followed_users = user_follows.find(i);

        vpii scores; // scores stored as (score, story number)
        fo(k, 1, n + 1)
        {
            int total_score = 0;

            if (i_created_stories != story_creations.end())
                if (cpresent(story_creations.at(i), k))
                    total_score = -1; // user i created story k

            if (i_followed_stories != story_follows.end())
                if (cpresent(story_follows.at(i), k))
                    total_score = -1; // user i follows story k

            if (total_score != -1)
            {
                fo(j, 1, m + 1)
                {
                    auto j_followed_stories = story_follows.find(j);
                    auto j_created_stories = story_creations.find(j);

                    int a_score = 0, b_score = 0;
                    bool a_score_found = false, b_score_found = false;

                    if (i == j) // same user
                    {
                        a_score_found = true;
                        a_score = 0;
                    }

                    if (a_score_found == false)
                    {
                        if (i_followed_users != user_follows.end())
                        {
                            if (cpresent(user_follows.at(i), j)) // user i follows user j
                            {
                                a_score_found = true;
                                a_score = 3;
                            }
                        }

                        if (a_score_found == false)
                        {
                            if (i_followed_stories != story_follows.end())
                            {
                                if (j_created_stories != story_creations.end())
                                {
                                    // for (int story_created_by_j : story_creations.at(j))
                                    // {
                                    //     if (cpresent(story_follows.at(i), story_created_by_j)) // user i follows story created by user j
                                    //     {
                                    //         a_score_found = true;
                                    //         a_score = 2;
                                    //     }
                                    // }
                                    if (check_any_matching(story_follows.at(i), story_creations.at(j))) // user i follows story created by user j
                                    {
                                        a_score_found = true;
                                        a_score = 2;
                                    }
                                }

                                if (a_score_found == false)
                                {
                                    if (j_followed_stories != story_follows.end())
                                    {
                                        // for (int story_followed_by_j : story_follows.at(j))
                                        // {
                                        //     if (cpresent(story_follows.at(i), story_followed_by_j)) // user i follows story followed by user j
                                        //     {
                                        //         a_score_found = true;
                                        //         a_score = 1;
                                        //     }
                                        // }
                                        if (check_any_matching(story_follows.at(i), story_follows.at(j))) // user i follows story followed by user j
                                        {
                                            a_score_found = true;
                                            a_score = 1;
                                        }
                                    }
                                }
                            }
                        }
                    }

                    if (j_created_stories != story_creations.end())
                    {
                        if (cpresent(story_creations.at(j), k)) // user j created story k
                        {
                            b_score_found = true;
                            b_score = 2;
                        }
                    }

                    if (b_score_found == false)
                    {
                        if (j_followed_stories != story_follows.end())
                        {
                            if (cpresent(story_follows.at(j), k)) // user j follows story k
                            {
                                b_score_found = true;
                                b_score = 1;
                            }
                        }
                    }

                    total_score += a_score * b_score;
                }
            }
            scores.pb(mp(total_score, k));
        }

        sort(scores.begin(), scores.end(), [](pii a, pii b) {
            if (a.fi == b.fi)
                return a.se < b.se;
            else
                return a.fi > b.fi;
        });

        recommendations.pb(scores);
    }

    fo(i, 0, m)
    {
        cout << recommendations[i][0].se << " " << recommendations[i][1].se
             << " " << recommendations[i][2].se << "\n";
    }

    return 0;
}