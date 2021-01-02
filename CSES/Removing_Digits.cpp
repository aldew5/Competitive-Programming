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


ll dp[1000001][2];

int main ()
{
    ll n;
    cin >> n;

    for (int i = 0; i <= n; i++){
        dp[i][0] = INT_MAX;
    }

    dp[n][0] = 0;
    dp[n][1] = 1;

    for (int i = n; i >= 0; i--){
        string s = to_string(i);
        vector<int> vals;
        for (auto u : s)
            vals.pb(u - '0');
        for (auto j : vals){
            if (!dp[i][1])
                continue;

            //cout << i << " " << j << endl;
            dp[i -j][0] = min(dp[i][0] + 1, dp[i-j][0]);
            dp[i-j][1] = 1;
        }
    }
    cout << dp[0][0] << endl;


    return 0;
}



