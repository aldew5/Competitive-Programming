/*
ID: alec3
LANG: C++14
PROG:
/*
Pick an arbitrary node a.  DFS from a to a leaf then DFS from the leaf (b) to
the corresponding leaf c. The distance between b and c is the diameter.
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

int n;
vector<int> adj[200001];

int leaf = -1;
bool visit[200001];
int ans = 0;

void dfs(int n, int c){
    if (visit[n])
        return;

    visit[n] = true;
    if (c > ans)
        leaf = n;
    ans = max(ans, c);


    for (auto u : adj[n])
        dfs(u, c+1);

    return;
}



int main ()
{
    cin >> n;
    int a, b;
    F0R(i, n-1){
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    dfs(1, 0);
    for (int i = 0; i <= n; i++)
        visit[i] = false;
    //cout << "LEAF is " << leaf << endl;
    ans = 0;
    dfs(leaf, 0);



    cout << ans << endl;

}

