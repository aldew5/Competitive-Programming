
/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Credit to Dhruv Rhatgi
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

// dp[i] is the optimal sum of skill levels
// achieved by the first i cows
int dp[10001];

int main()
{
    setIO("teamwork");

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& it : a) cin >> it;

    // first team is just the first cow
    dp[0] = a[0];

    for (int i = 1; i < n; i++){
        // set an initial max
        int mx = a[i];
        // for all the team sizes from i to i - k
        for (int j = i; j >= 0 && i + 1 - j <= k; j--){
            // update the max value
            mx = max(mx, a[j]);
            // reached k
            if (j == 0)
                // full team * max value
                dp[i] = max(dp[i], mx * (i + 1 -j));
            else
                // if we make team of size i + 1 -j update
                // dp[i]
                dp[i] = max(dp[i], dp[j-1] + mx * (i + 1 -j));
        }
    }
    // max value
    cout << dp[n-1] << endl;


}

