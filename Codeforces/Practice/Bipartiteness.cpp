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

vector<int> adj[100001];
ll cnt[2];

void dfs(int node, int prev, int c){
    // count the number of each color
    cnt[c] ++;
    for (int i = 0; i < adj[node].size(); i++){
        if (adj[node][i] != prev)
            dfs(adj[node][i], node, !c);
    }
}

int main()
{
    //setIO("mootube");
    int n;
    cin >> n;
    int u, v;
    for (int i = 0; i < n-1; i++){
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    // color the graph
    dfs(1, 1, 0);
    // the answer is the product of the colors - n + 1
    // the max edges is cnt[0] * cnt[1]
    // we already have n -1
    // there can only be edges between nodes in different groups
    cout << cnt[0] * cnt[1] - (n - 1) << endl;

    return 0;
}
