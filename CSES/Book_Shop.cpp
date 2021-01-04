/*
ID: alec3
LANG: C++14
PROG:
/*
CASE OF THE 0-1 KNAPSACK
*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" " << endl;
#define line cout << "--------------" << endl;
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ld long double

#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, n) for (int i = 0; i < n; i++)


typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

const ll MOD = 1000000000 + 7;

// dp[i][x] is the maximum number of pages we can get for a price less than
// or equal to x, only buying among the first i books
int dp[1001][100001];

int main ()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (auto& it : a) cin >> it;
    for (auto& it : b) cin >> it;

    // redundant, but you can't get any pages without any books
    for (int i = 0; i <= x; i++)
        dp[0][x] = 0;

    // loop through books
    for (int i = 1; i <= n; i++){
        // loop through prices
        for (int j = 0; j <= x; j++){
            // we can definitely buy the same number of pages as we
            // could without including the ith book
            dp[i][j] = dp[i-1][j];
            // the remaining money is j - the price of the ith book (zero indexed)
            int r = j - a[i-1];

            // we can afford it
            if (r >= 0){
                // we can buy max(dp[i][j], dp[i-1][r] + b[i-1]) pages with at most j dollars
                // using only the first i books
                dp[i][j] = max(dp[i][j], dp[i-1][r] + b[i-1]);
            }
        }
    }

    // output
    cout << dp[n][x] << endl;

    return 0;
}



