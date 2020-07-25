/*
ID: Aldew
LANG: C++14
PROG: M's Solution
credit to yutaka1999
*/
/*

*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define INF 11000000000000000LL

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

//ifstream fin("lamps.in");
//ofstream fout("lamps.out");
const int BT = (1 << 16);

int x[20], y[20], p[20];
ll score[BT];
ll dp[BT][20];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n ;i++) cin >> x[i] >> y[i] >> p[i];
    for (int s = 1; s < 1 << n; s++){
        score[s] = INF;

        for (int i = 0; i < n; i++){
            int xi = x[i];
            ll sx = 0;
            for (int k = 0; k < n; k++){
                if (s >> k & 1)
                    sx += (ll) abs(x[k] - xi) * (ll) p[k];
            }
            score[s] = min(score[s], sx);

            int yi = y[i];
            ll sy = 0;
            for (int k = 0; k < n; k++){
                if (s >> k & 1)
                    sy += (ll) abs(y[k] - yi) * (ll) p[k];
            }
            score[s] = min(score[s], sy);
        }
    }
    for (int s = 0; s < 1 << n; s++){
        ll score = 0;
        for (int k = 0; k < n; k++){
            if (s >> k&1)
                score += (ll) min(abs(x[k]), abs(y[k])) * (ll) p[k];
        }
        for (int k = 0; k <= n; k++){
            dp[s][k] = score;
        }
    }
    for (int k = 0; k <= n; k++) dp[0][k] = 0;
    for (int s = 0; s < 1 << n; s++){
        for (int k = 0; k < n; k++){
            if (dp[s][k] == INF) continue;

            int z = (1 << n) - 1 - s;
            for (int t = z; t > 0; t = (t-1) & z){
                dp[s|t][k+1] = min(dp[s|t][k+1], dp[s][k] + score[t]);
            }
        }
    }
    for (int i = 0; i <= n; i++){
        cout << dp[(1 << n ) - 1][i] << endl;
    }



    return 0;
}
