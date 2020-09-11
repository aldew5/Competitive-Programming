/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Initially we set the values in the dp array to max so that
we're not picking zero as the min cost on a particular day
when the min cost isn't really zero.

We loop through the days and realize that we have three options
on each day: do nothing, go to the gym, do a contest. We can always
do nothing so we have that at the start of the loop. The cost of doing
nothing is always 1 + the minimum cost of getting there.

If we have a 1 or a 3 we can do a contest. We do the contest the min times
of doing gym or nothing the previous day.

If we have a 2 or a 3 we can go to the gym. The total min cost of doing the gym on
the ith day, is the min cost of doing nothing or a contest on the previous days.

We return the min value.
*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define FOR(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

ifstream fin("0.in");
ofstream fout("ans.out");

// store the min cost if we do the jth activity on the ith day
int dp[101][3];

int main()
{
    // set values to max. This makes it so that doing nothing
    // is always picked instead of zero
    memset(dp, 63, sizeof(dp));

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; i++)
        cin >> a[i];

    dp[0][0] = 0;
    for (int j = 1; j <= n; j++){
        // you can always do nothing
        // which gives the result of the min time of completing the first days
        dp[j][0] = min({dp[j-1][0] + 1, dp[j-1][1] + 1, dp[j-1][2] + 1});

        // contest or both
        if (a[j] == 1 || a[j] == 3){
            // if we do the contest on the ith day, we can do it the min
            // times of doing nothing the previous j-1 or doing the gym the previous days
            dp[j][1] = min(dp[j-1][0], dp[j-1][2]);
        }
        // gym or both
        if (a[j] == 2 || a[j] == 3)
            // we can go to the gym the min times we can do a contest
            // or nothing the previous days
            dp[j][2] = min(dp[j-1][0], dp[j-1][1]);
    }
    // min result
    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << endl;
    //cout << dp[n][0] << " " << dp[n][1] << " " << dp[n][2] << endl;

    return 0;
}
