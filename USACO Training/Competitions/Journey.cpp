/*
ID: alec3
LANG: C++14
PROG:
/*

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
vector<int> adj[100001];


ld dfs(int n, int c = -1){
    // the sum of all path lengths
    ld sum = 0;
    // all possible nodes
    for (auto u : adj[n])
        // if the node isn't the previous node
        if (u != c)
            // we add the length of the path past u and 1 for the
            // current node (n)
            sum += dfs(u, n) + 1;
    // output 0 if sum is 0, otherwise the total sum / number of paths
    return sum ? sum / (adj[n].size() - (c != -1)) : 0;
}

int main()
{
    cin >> n;
    int v, u;
    // read input
    F0R(i, n-1){
        cin >> v >> u; v--; u--;
        adj[v].pb(u); adj[u].pb(v);
    }
    cout << fixed << setprecision(9) << dfs(0) << endl;
    return 0;
}
