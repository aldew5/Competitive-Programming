
/*
This is a disjoint set problem made vastly easier with the 
template. Just output the number with the most connections.
*/


#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ld long double
#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

//ifstream fin("maze1.in");
//ofstream fout("maze1.out");
struct UnionFind{
	int size;
	vector<int> parent;

	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++) parent[i] = i;
	}
	int root(int i){
		if(parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}
	bool same(int i, int j){
		return root(i) == root(j);
	}
	void unite(int i, int j){
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j) return;
		parent[root_i] = root_j;
	}
};
ll n, m;
UnionFind uf(200005);
map<ll, ll> mp;


int main()
{
    io;
    cin >> n >> m;
    ll a, b;
    for (int i = 1; i <= m; i++){
        cin >> a >> b;
        uf.unite(a, b);
    }

    for (int i = 1; i <= n; i++)
        mp[uf.root(i)] ++;

    ll ans = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
        ans = max(ans, it->second);
    cout << ans << endl;
    return 0;
}
