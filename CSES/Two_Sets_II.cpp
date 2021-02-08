
/*
ID: alec3
LANG: C++14
PROG:
*/
/*

*/


#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" " << endl;
#define line cout << "--------------------" << endl;
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = 1e10 + 70;
const ll MX = 2 * 1e6;

void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}

// dp[i][x] = number of ways to make sum x using
// subsets of the numbers 1..i

int dp[501][100001];

int main()
{

    int n;
    cin >> n;
    // sum of first n terms
    int sum = n * (n + 1) /2;

    // if sum is odd it can't be spilt equally
    // into two groups
    if (sum % 2){
        cout << 0 << endl;
        return 0;
    }
    sum /= 2;

    dp[0][0] = 1;
    // numbers up to n
    for (int i = 1; i < n; i++){
        // build have the set
        for (int j = 0; j <= sum; j++){
            // we can build the sum j using the first i numbers
            // the same number of times we can build it
            // with the first i -1 numbers
            // (different set?)
            dp[i][j] = dp[i-1][j];
            // reamining sum
            int r = j - i;
            if (r >= 0){
                // add the number of ways to make the other set
                dp[i][j] += dp[i-1][r];
                // compute mod
                dp[i][j] %= MOD;
            }

        }
    }
    cout << dp[n-1][sum] << endl;

}

