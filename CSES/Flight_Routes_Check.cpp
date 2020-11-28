/*
ID: alec3
LANG: C++14
PROG:
/*
Credit to Michael Cao
*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" " << endl;
#define line cout << "--------------" << endl;
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ld long double
#define mp make_pair

#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, n) for (int i = 0; i < n; i++)


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

// two-dimensional adj
vector<int> adj[100005][2]; bool visit[100001];

void dfs(int v, int x){
    visit[v] = true;
    // for all the places we can go to from 
    // what is the second dimension?
    // it just gets repassed in 
    for (int to : adj[v][x]){
        if (!visit[to])
            dfs(to, x);
    }
}

int main()
{
    //setIO("fenceplan");
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u --; v --;
        // we can fly from from city u to v
        adj[u][0].pb(v);
        // we can't necessarily travel from v to u
        adj[v][1].pb(u);
    }
    
    // dfs from city 0 will go through all possible cities
    // we can get to from 0 and update the visit array
    dfs(0, 0);
    for (int i = 0; i < n; i++){
        // if we didn't get to any of the cities
        // it's not possible and we know the 0 (1) flight can't 
        // get to i (i + 1)
        if (!visit[i]){
            cout << "NO" << endl;
            cout << 1 << " " << i + 1 << endl;
            return 0;
        }
    }
    // reset visit
    memset(visit, false, sizeof(visit));
    // dfs from city 1 except this time go through all the cities
    // it can't explicitly fly to 
    dfs(0, 1);
    for (int i = 0; i < n; i++){
        // if by starting at cities we may not be able to 
        // visit we either don't visit all of these or 
        // don't get to the ones
        if (!visit[i]){
            // not possible
            cout << "NO" << endl;
            cout << i + 1 << " " << 1 << endl;
            return 0;
        }
    }
    // 
    cout << "YES" << endl;




    return 0;
}
