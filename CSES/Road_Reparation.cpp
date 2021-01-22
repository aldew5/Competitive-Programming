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


using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = 1e10 + 70;
const ll MX = 2 * 1e6;

struct DSU {
    vector<int> e; void init(int N) { e = vector<int>(N,-1); }
    // get representive component, uses path compression
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) { // union by size
        x = get(x), y = get(y); if (x == y) return 0;
        if (e[x] > e[y]) swap(x,y);
        e[x] += e[y]; e[y] = x; return 1;
    }
};

int comp;
template<class T> T kruskal(int N, vector<pair<T,pair<ll, ll>>> ed) {
    sort(ed.begin(), ed.end());
    T ans = 0; DSU D; D.init(N+1); // edges that unite are in MST
    for (auto& a : ed)
        if (D.unite(a.ss.ff,a.ss.ss)) {
            ans += a.ff;
            comp--;
        }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<ll, pair<ll, ll>>> x;
    F0R(i, m){
        ll a, b, c;
        cin >> a >> b >> c;
        x.pb({c, {a, b}});
    }
    comp = n;
    ll ans = kruskal(n, x);
    // if we didn't do n-1 comparisons then the cities
    // coudln't be connected
    // otherwise kruskals will output the cost of the MST
    if (comp == 1)
        cout << ans << endl;
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}
