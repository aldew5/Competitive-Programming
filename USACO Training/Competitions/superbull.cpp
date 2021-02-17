
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

const ll INF = 1e10 + 70;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;

void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}


ll XOR(ll x, ll y){
    ll res = 0; // Initialize result

    // Assuming 32-bit Integer
    for (int i = 31; i >= 0; i--){
       // Find current bits in x and y
       bool b1 = x & (1 << i);
       bool b2 = y & (1 << i);

        // If both are 1 then 0 else xor is same as OR
        bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);

        // Update result
        res <<= 1;
        res |= xoredBit;
    }
    return res;
}

struct DSU {
    vector<int> e; void init(int N) { e = vector<int>(N,-1); }
    // get representive component, uses path compression
    int get(int x) {  return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) { // union by size

        x = get(x), y = get(y);

        if (x == y) { return 0;}

        if (e[x] > e[y]) swap(x,y);

        e[x] += e[y]; e[y] = x; return 1;
    }
};

int comp;
template<class T> T kruskal(int N, vector<pair<T,pair<int, int>>> ed) {
    sort(ed.rbegin(), ed.rend());
    T ans = 0; DSU D; D.init(N+1); // edges that unite are in MST
    for (auto& a : ed){

        if (D.unite(a.ss.ff,a.ss.ss)) {
            ans += a.ff;
            comp--;
        }

    }
    return ans;
}

int main()
{
    setIO("superbull");
    int n;
    cin >> n;
    vector<pair<ll, pair<int, int> > > edge;

    vector<int> b(n);
    for (auto& it : b) cin >> it;

    for (int i = 0; i < n; i++){
        for (int j= i + 1; j < n; j++){

            edge.pb({XOR(b[i], b[j]), {i, j}});

        }
    }

    ll ans = kruskal(n, edge);
    cout << ans << endl;

}

