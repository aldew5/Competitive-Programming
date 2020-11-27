/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Credit to Oscar Garries
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

template<class T, int SZ> struct PrefixSums {
    T sum[SZ][SZ];
    PrefixSums () { memset(sum,0,sizeof sum); }
    // 2D prefix sum
    void init() {
        FOR(i,1,SZ) FOR(j,1,SZ)
        sum[i][j] += sum[i][j-1]
        +sum[i-1][j]-sum[i-1][j-1];
    }
    // get the sum for a given range
    T get(int X1, int X2, int Y1, int Y2) {
        return sum[X2][Y2]-sum[X1-1][Y2]
        -sum[X2][Y1-1]+sum[X1-1][Y1-1];
    }
};


using namespace std;

vector<pair<int, int> > g[5001];
vector<bool> visit(5001);
int k, v, ans =0;

void dfs(int v) {
    visit[v] = true;
    for (auto x: g[v]){
        if(visit[x.ff])
            continue;
        if (x.ss >= k){
            ans ++;
            dfs(x.ff);
        }
    }
    return;

}


int main()
{
    setIO("mootube");
    int n,q; cin >> n >> q;

    for (int i = 0; i < n -1; i++){
        int a,b, r;
        cin >> a >> b >> r;
        g[a].pb(mp(b, r)); g[b].pb(mp(a, r));
    }


    while (q--){
        cin >> k >> v;
        ans = 0;
        vector<bool> vS(n + 1);
        visit = vS;
        dfs(v);

        cout << ans << endl;
    }

    return 0;
}
