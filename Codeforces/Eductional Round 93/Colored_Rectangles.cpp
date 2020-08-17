/*
ID: alec3
LANG: C++14
PROG:
*/
/*
dp problem.
*/


#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ld long double
#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int MAXN = 200;
int R, G, B, r[MAXN], g[MAXN], b[MAXN];
int dp[MAXN + 1][MAXN + 1][MAXN + 1];

int main()
{
    io;
    cin >> R >> G >> B;
    for (int i = 0; i < R; i++)
        cin >> r[i];
    for (int i = 0; i < G; i++)
        cin >> g[i];
    for (int i = 0; i < B; i++)
        cin >> b[i];

    sort(r, r + R);
    sort(g, g + G);
    sort(b, b + B);

    for (int i = 0; i <= R; i++){
        for (int j = 0; j <= G; j++){
            for (int k = 0; k <= B; k++){\
                if (i && j)
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + r[i-1] * g[j-1]);
                if (i && k)
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + r[i-1] * b[k-1]);
                if (k && j)
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + g[j-1] * b[k-1]);
            }
        }
    }
    cout << dp[R][G][B] << endl;


    return 0;

}
