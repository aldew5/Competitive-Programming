/*
ID: alec3
LANG: C++14
PROG:
/*
Credit to Benq

We can think of this by merging equivalent nodes together into connected
components. The only way it doesn't work, is if there is one connected
component from a to b with the wrong cow. 
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


int n, m, comp[100001], num;
char col[100001];
vector<int> adj[100001];

void dfs(int n){
    // already created a component
    if (comp[n])
        return;
    comp[n] = num;
    for (auto u : adj[n])
        // still the same component
        if (col[u] == col[n])
            dfs(u);

    return;
}

int main ()
{
    setIO("milkvisits");
    cin >> n >> m;
    string s; cin >> s;
    // store chars in col
    FOR(i, 1, n + 1)
        col[i] = s[i-1];

    int a, b;
    F0R(i, n-1){
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    
    // loop through i to n and build the components 
    // with a DFS
    FOR(i, 1, n + 1){
        if (!comp[i]){
            num ++;
            dfs(i);
        }
    }

    string ans = "";
    F0R(i, m){
        char c; cin >> a >> b >> c;
        // if they are the same and col[a] is required or 
        // the end components are different
        if (col[a] == c || comp[a] != comp[b])
            ans += '1';
        else
            ans += '0';
    }
    cout << ans << endl;
}

