/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Credit to Mark Chen
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

struct DSU {
    vector<int> e;
    void init (int n) { e = vector<int> (n, -1); }
    int get (int x) { return (e[x] < 0 ? x : e[x] = get(e[x])); }
    bool sameSet (int x, int y) { return get(x) == get(y); }
    int size (int x) { return -e[get(x)]; }
    bool unite (int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

void union_init(int d[], int s) { for (int i=0; i < s; i++) d[i]=i; }
int union_query(int d[], int n) { int res=n; while (d[res]!=res) res=d[res]; int m; while (d[n]!=n) {m=d[n];d[n]=res;n=m;} return res; };
int union_merge(int d[], int x, int y) { x=union_query(d,x); y=union_query(d,y); if (x==y)return -1; d[x]=y; return 1; }


int order[200010], place[200001], u[200001], v[200001], par[200001];
bool res[200001];

vector<vector<int> > adj;
int main()
{
    setIO("closing");
    int n, m;
    cin >> n >> m;

    int x, y;

    for (int i = 0; i < m; i++){
        cin >> x >> y;
        u[i] = x; v[i] = y;
    }

    for (int i = 0; i < n; i++){
        cin >> x;
        order[i] = x;
        place[order[i]] = i;
    }

    adj.resize(n + 1);

    for (int i = 0; i < m; i++){
        if (place[u[i]] > place[v[i]])
            adj[v[i]].pb(u[i]);
        else
            adj[u[i]].pb(v[i]);
    }
    union_init(par, n + 1);

    int comps = 0;

    for (int i = n-1; i >= 0; i--){
        int u = order[i]; comps ++;

        for (int j = 0; j < adj[u].size(); j++){
            int va = adj[u][j];
            if (union_query(par, u) != union_query(par, va)){
                union_merge(par, u, va);
                comps --;
            }
        }
        res[i] = (comps <= 1);
    }

    for (int i = 0; i < n; i++){
        if (res[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }



    return 0;
}
