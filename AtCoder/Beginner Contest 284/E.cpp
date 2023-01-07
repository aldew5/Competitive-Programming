// Aldew
 
 
 
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
 
 
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
 
 
map<int, int> freq;
int n, m;
vector<int> adj[2 * 100000 + 1];
map<int, int> visit;
int ans = 0;
void dfs(int n){
    if (visit[n]){
        return;
    }
    ans ++;
    if (ans >= 1000000) {
        return;
    }
    visit[n] = true;
    for (auto u : adj[n]) {
        if (!visit[u]){
            dfs(u);
        }
    }
            
        visit[n] = false;
}
 
void solve() {
    
    cin >> n >> m;
    
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    
    dfs(1);
    cout << min(ans, 1000000) << endl;
    
    
   
    return;
}
 
 
 
 
int main() {
    io;
    int T = 1;
    while (T --) {
        solve();
    }
 
    return 0;
