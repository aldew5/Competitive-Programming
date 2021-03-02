/*
ID: alec3
LANG: C++14
PROG:
*/
/*

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

int n, m, ans;
int visit[100001];
vector<int> a[100001], b[100001];

bool possible = true;

void dfs(int u, int v){
    // visited
    visit[u] = v;
    for (auto i : a[u]){
        // color system
        if (visit[i] == 3-v){
            possible = false;
            //cout << i << endl;
        }
        if (visit[i] == 0)
            dfs(i, v);
    }
    for (auto i : b[u]){
        if (visit[i] == v){
            possible = false;
        }
        if(visit[i] == 0)
            dfs(i, 3-v);
    }

}


int main()
{
    setIO("revegetate");
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int y, z;
        string s;
        cin >> s >> y >> z;
        // a cow that must have the same type of grass
        if (s == "S"){
            a[y].pb(z); a[z].pb(y);
        }
        // different type of grasses
        else {
            b[z].pb(y); b[y].pb(z);
        }

    }
    // loop through the cows
    for (int i = 1; i <= n; i++){
        // haven't seen it (doesn't share a field with another cow)
        if (!visit[i]){
            // dfs
            dfs(i, 1);
            // found a valid connection from this node
            // there are two possibilities (reversing the groups)
            ans ++;
        }
    }
    
    // not bipartite
    if (!possible)
        cout << 0 << endl;
    else {
        cout << 1;
        for (int i = 0; i < ans; i++)
            cout << 0;
        cout << endl;
    }

    return 0;
}
