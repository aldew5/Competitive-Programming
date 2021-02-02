/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Credit to Mark Chen
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
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}

ll n, m, c;
// store values of cities
ll value[1001];
ll dp[2][1001];

vector<pair<int, int>> edges;

int main()
{
    setIO("time");
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++){
        cin >> value[i];
    }
    int x, y;
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        edges.pb({x, y});
    }

    ll mx = 0;
    // set every value in dp to -1
    memset(dp, -1, sizeof dp);
    dp[0][1] = 0;

    // if C = 1 we have
    // 1000t - t^2 as the bound for the profit
    // 1000t(1 - t)
    // since we already have a 0 value a t > 1
    // and the expression is negative when t > 1000 we have an upper bound
    for (int t = 1; t < 1001; t++) {
        // if the time is divisible by 2 p = 0
        // else p = 1
        // p is going to alternate between 1 and 2
		int p = t % 2;
		memset(dp[p], -1, sizeof dp[p]);
        // loop through edges
		for (auto e : edges) {
            // 1-p is going to be the other value for p
            // visit or not visit?
			if (dp[1-p][e.ff] >= 0) {
			    // the value of visiting or not visiting the e.ss city
			    // depending on p
			    // is the max of that value and the opposite at the first city + 
			    // the value of the second city
				dp[p][e.ss] = max(dp[p][e.ss], dp[1-p][e.ff] + value[e.ss]);
			}
		}
		// compute the cost
		// 
		mx = max(mx, dp[p][1] - c * t * t);
	}
	cout << mx << "\n";

    return 0;

}
