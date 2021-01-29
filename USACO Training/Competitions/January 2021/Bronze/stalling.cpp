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

const ll MOD = 1e9 + 7;
const ll INF = 1e10 + 70;
const ll MX = 2 * 1e6;

vector<int> adj[21];
bool visit[22];

int n;

//void dfs(int node, int stall){
//    visit[stall] = true;
//    if (node == n){
//        ans ++;
//        //cout << "END" << endl;
//        return;
//    }
//    // all the stalls node can occupy
//    for (auto u : adj[node]){
//        if (!visit[u]){
//            //cout << node << " " << u << endl;
//            dfs(node + 1, u);
//            visit[u] = false;
//        }
//    }
//}


int main()
{
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto& it : a) cin >> it;
    for (auto& it : b) cin >> it;


    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 1;
    int index = 0;
    for (int i =0; i < b.size(); i++){
        while (index < a.size() && a[index] <= b[i]){
            index ++;
        }
        if (index >= a.size() || a[index] > b[i])
            index --;
        // index + 1 cows can go in bucket i
        //cout << "INDEX " << index << endl;
        if (i == 0 && index != -1){
            ans *= (index + 1);
            //cout << "i: " <<  index + 1 << endl;
        }
        else{
            //cout << "i: " << endl;
            //cout << "HERE " << index << " " << i << endl;
            //cout << "MULTI BY " << index + 1 -i << endl;
            ans *= (index + 1 - i);
        }
        //cout << ans << endl;
    }

    cout << ans << endl;





    return 0;
}
