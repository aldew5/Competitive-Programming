
/*
ID: alec3
LANG: C++14
PROG:
/*

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

// dp[i][x]
// the number of ways to pick coins with sum x, using the first
// i coins (because they must be ordered)
ll dp[101][1000005];

int main ()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> c(n);
    for (auto& it : c) cin >> it;

    // empty set
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++){
        F0R(j, x + 1){
            // set it to the number of times we can make the sum
            // j with the first i-1 coins
            dp[i][j] = dp[i-1][j];
            // the remainder is the difference between our current
            // value and the next coin (zero indexed)
            ll r = j -c[i-1];

            // positive difference
            if (r >= 0){
                // add the number of times we can make the sum
                // r with the first i coins
                // this still follows the ordering convention
                dp[i][j] += dp[i][r];
                dp[i][j] %= MOD;
            }
        }

    }



    cout << dp[n][x] << endl;



    return 0;
}



