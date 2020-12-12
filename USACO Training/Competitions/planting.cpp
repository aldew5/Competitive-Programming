/*
ID: alec3
LANG: C++14
PROG:
/*
Every time we connect a node to a node with a degree >= 2 we must add a color.

Just DFS and
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

vector<int> adj[100001];

int main ()
{
    setIO("planting");
    int n; cin >> n;
    int a, b;
    F0R(i, n-1){
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }

    int ans = 0;
    F0R(i, n){
        ans = max(ans, int(adj[i].size()+ 1));
    }
    cout << ans << endl;

    return 0;

}

