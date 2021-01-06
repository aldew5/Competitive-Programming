/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Credit to icecuber
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


using namespace std;

const ll MOD = 1e9 + 7;
int dp[100001][101];

int main()
{
    int n, m;
    cin >> n >> m;

    int x0;
    cin >> x0;
    if (x0 == 0){
        for (int i = 1; i<= 100; i++)
            dp[0][i] = 1;
    }
    else
        dp[0][x0] = 1;

    for (int i = 1; i < n; i++){
        int x;
        cin >> x;

        if (x == 0){
            for (int j = 1; j <= m; j++){
                for (int k : {j-1, j, j+1}){
                    if (k >= 1 && k <= m){
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= MOD;
                    }

                }
            }
        }
        else {
            for (int k : {x-1, x, x+1}){
                if (k >= 1 && k <= m){
                    dp[i][x] += dp[i-1][k];
                    dp[i][x] %= MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int j =1; j <=m; j++){
        ans += dp[n-1][j];
        ans %= MOD;
    }
    cout << ans << endl;



    return 0;
}
