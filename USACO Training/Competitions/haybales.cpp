/*
ID: alec3
LANG: C++14
PROG: haircut
*/
/*
Figure out which cows are connected by a broadcast and then
dfs on the adjacency array.
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

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}

int main() {
    setIO("haybales");
    int n, q;
    cin >> n >> q;
    vector<int> v(n);

    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(begin(v),end(v));

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << upper_bound(begin(v),end(v), b)-lower_bound(begin(v),end(v), a) << endl;
    }
    return 0;
}
