/*
ID: alec3
LANG: C++14
PROG:
/*
Just add the greatest weight (to the oringal count) the number of
times there are edges out of it. Essentially we double it up optimally
(when we count it for each edge)

Credit to tourist for the clever solution
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

ull dp[1000001];

int main ()
{
    ll n; cin >> n;
    // one way to make 0 (empty set)
    dp[0] = 1;

    for (int i = 1; i <= n; i++){
        // the number of ways we can make a sum
        // that is reachable with a number 1-6
        for (int j = 1; j <= 6; j++){
            if (j > i)
                break;
            dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
    }
    cout << dp[n] << endl;


    return 0;
}



