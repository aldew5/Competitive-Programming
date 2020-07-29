/*
ID: alec3
LANG: C++14
PROG: money
*/
/*
Classic dp problem except we're looking
for combinations of coins rather than
permutations so we can only use each coin
once in the loop.
*/


#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

ifstream fin("money.in");
ofstream fout("money.out");

ll dp[10001];
int main()
{
    int v, n;
    fin >> v >> n;
    vector<int> coins;

    int it;
    while (v--){
        fin >> it;
        coins.pb(it);
    }

    dp[0] =1;
    int c = 0;
    for (int x = 1; x <= n; x++){
        ll coin = coins[c];

        for (int j = coin; j <= n; j++){
            dp[j] += dp[j-coin];
        }
        c ++;
        if (c == coins.size()) break;
    }

    fout << dp[n] << endl;



    return 0;
}
