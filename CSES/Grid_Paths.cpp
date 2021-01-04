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

int grid[1001][1001];
int dp[1001][1001];


int main ()
{
    int n;
    cin >> n;

    char it;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> it;
            if (it == '.')
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
        }
    }

    if (!grid[0][0]){
        cout << 0 << endl;
        return 0;
    }

    dp[0][0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (!grid[i][j])
                continue;
            if (i > 0)
                dp[i][j] += dp[i-1][j];
            if (j > 0)
                dp[i][j] += dp[i][j-1];

            dp[i][j] %= MOD;
        }
    }


    cout << dp[n-1][n-1] << endl;


    return 0;
}



