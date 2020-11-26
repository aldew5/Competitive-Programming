/*
ID: alec3
LANG: C++14
PROG:
/*
Credit to Brian Dean
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
vector<pair<ll, ll> > C;
vector<ll> adj[100000];

int visit[100000];

struct Box {
    ll x1, x2, y1, y2;
};

void dfs(int a, int c, Box& b) {
    visit[a] = c;
    b.x1 = min(b.x1, C[a].ff);
    b.x2 = max(b.x2, C[a].ff);
    b.y1 = min(b.y1, C[a].ss);
    b.y2 = max(b.y2, C[a].ss);

    for (int i : adj[a]){
        if (!visit[i])
            dfs(i, c, b);
    }
}

int main()
{
    setIO("fenceplan");
    cin >> n >> m;
    pair<ll, ll> p;
    for (int i = 0; i < n; i++){
        cin >> p.ff >> p.ss;
        C.pb(p);
    }
    for (int i = 0; i < m; i++){
        cin >> p.ff >> p.ss;
        adj[p.ff -1].pb(p.ss -1);
        adj[p.ss-1].pb(p.ff-1);
    }

    ll k = 0, best = INT_MAX;
    for (int i = 0; i < n; i++){
        if (!visit[i]){
            Box b = {INT_MAX, 0, INT_MAX, 0};
            dfs(i, k + 1, b);
            best = min(best, 2 * (b.x2 - b.x1 + b.y2 - b.y1));
        }
    }
    cout << best << endl;




    return 0;
}
