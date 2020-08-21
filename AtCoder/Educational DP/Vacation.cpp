/*
ID: alec3
LANG: C++14
PROG: ttwo
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

ifstream fin("ttwo.in");
ofstream fout("ttwo.out");
// a will contain the three choices
// for each day
int a[100000][3], dp[100000][3];

int main()
{
    io;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    }
    // initialize the dp array
    for (int j = 0; j < 3; j++)
        dp[0][j] = a[0][j];

    // loop through days
    for (int i = 1; i < n; i++){
        // loop through activities
        for (int j = 0; j < 3; j++){
            int mx = 0;
            // for each of the starting points
            // find the max value for the next day
            for (int k = 0; k < 3; k++){
                // not the same activity
                if (k != j)
                    mx = max(dp[i-1][k], mx);
                // update the array
                dp[i][j] = mx + a[i][j];
            }
        }
    }
    // update the max result over all the days
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});

    return 0;
}
