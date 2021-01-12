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

int grid[101][101];

int main()
{
    int n, m; cin >> n >> m;
    vector<pair<int, int> > q;

    int x, y;
    F0R(i, m){
        cin >> x >> y;
        q.pb({x-1, y-1});
    }

    for (auto i : q){
        for (int j = 0; j < n; j++)
            grid[j][i.ss] = 1;
        for (int j = 0; j < n; j++)
            grid[i.ff][j] = 1;

        grid[i.ff][i.ss] = 1;
        int a = i.ff, b = i.ss;

        while (a < n && b < n){
            grid[a][b] = 1;
            a ++; b++;
        }
        a = i.ff, b= i.ss;

        while (a >= 0 && b >= 0){
            grid[a][b] = 1;
            a --; b--;

        }
        a = i.ff; b = i.ss;
        while (a >= 0 && b < n){
            grid[a][b] = 1;
            a --; b ++;
        }
        a = i.ff; b = i.ss;
        while (a < n && b >= 0){
            grid[a][b] = 1;
            a ++; b--;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            if (!grid[i][j])
                ans ++;
    }
    cout << ans << endl;


    return 0;
}
