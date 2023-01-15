// Aldew



#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <set>


#define line cout << "--------------------" << endl;
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define vll vector<ll>
#define vi vector<int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

const ll INF = 1e10 + 70;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;


struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};


void solve() {
    int n;
    cin >> n;

    string a, b;
    vi v;


    DSU dsu(2*n+10);
    map<string, int> mp;
    int index = 1;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        if (!mp[a]) {
            mp[a] = index;
            index ++;
        }

        if (!mp[b]) {
            mp[b] = index;
            index ++;
        }
        if (dsu.get(mp[a]) == dsu.get(mp[b])) {
            cout << "No" << endl;
            return;
        }
        dsu.unite(mp[a], mp[b]);

    }

   cout << "Yes" << endl;
}

int main() {

    int T = 1;
    while (T --) {
       solve();
    }
    return 0;
}
