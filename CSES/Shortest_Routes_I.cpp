/*
ID: alec3
LANG: C++14
PROG:
*/
/*
PARTIALLY SOLVED
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
const ll INF = 1e10 + 70;

ll d[501][501];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j ++){
            d[i][j] = INF;
        }
    }

    ll a, b, c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--; b--;
        d[a][b] = c; d[b][a] = c;
    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (d[i][k] < INF && d[k][j] < INF){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }


    for (int i = 0; i < q; i++){
        cin >> a >> b;
        a--; b--;
        if (d[a][b] == INF)
            cout << "WRONG " << d[a][b] << endl;
        else
            cout << d[a][b] << endl;
    }


    return 0;
}
