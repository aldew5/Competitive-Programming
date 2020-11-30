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

int n, m;
vector<int> adj[100001];
bool good = true;
int color[100001];


void dfs(int node, int c){
    if (color[node]){
        if (color[node] != c){
            good = false;
            return;
        }
    }
    else {
        color[node] = c;
        if (c == 1)
            c = 2;
        else
            c = 1;

        for (auto u : adj[node])
            dfs(u, c);
    }
    return;
}



int main()
{
    //setIO("fenceplan");
    io;
    cin >> n >> m;
    int a, b;
    F0R (i, m){
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }

    for (int i = 1; i <= n; i++)
        if (!color[i])
            dfs(i, 1);

    dfs(1, 1);
    if (!good)
        cout << "IMPOSSIBLE" << endl;
    else {
        for (int i = 1; i <= n; i++){
            cout << color[i] << " ";
        }
        cout << endl;
    }



    return 0;

}
