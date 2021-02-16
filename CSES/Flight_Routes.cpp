
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
const ll MX = 1000000000000000L;

void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}

// declare arrays
vector<pair<ll, ll>> edge[200002];
ll dist[100001]; priority_queue<ll> best[100001];

vector<ll> ans;
int n, m, k;
// modified dj
void djikstra(int s){
    // contain pairs in a vector
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    // put the starting node on the pq
    // best stores lowest cost to s (which is zero since we start there)
    best[s].push(0); pq.push({0,s});

    while (pq.size()) {

        // top city (node)
        pair<ll, ll> a = pq.top(); pq.pop();

        // the cost of getting to the city
        // is greater than the best value (haven't found a better value)
        if (a.ff > best[a.ss].top())
            continue;

        // loop through the cities it's connected to
        for (auto& i: edge[a.ss]) {
            // the cost of getting to this city + the cost of getting to the next city
            ll tmp = a.ff+i.ss;

            // if we haven't found the k lowest costs yet
            if (best[i.ff].size() < k) {
                // push the running total of the cost of getting to
                // that city
                best[i.ff].push(tmp);
                // push the new city on {cost, city}
                pq.push({tmp, i.ff});
            }

            // we've found a better price
            else if (tmp < best[i.ff].top()) {
                // remove the greatest cost
                best[i.ff].pop();
                // push the better cost
                best[i.ff].push(tmp);
                // add the new node
                pq.push({tmp,i.ff});
            }
        }
    }
}

int main()
{
  io;

  cin >> n >> m >> k;
  // construct the edges a -> {cost, city}
  for (int i = 0; i < m; i++){
    ll a, b, c;
    cin >> a >> b >> c;
    pair<ll, ll> d = {b, c};
    edge[a].pb(d);
  }

    // init the arrays
    for (int i = 0; i < 100001; i++){
        dist[i] = MX;
    }
    // call djikstra and output
    djikstra(1);
    vector<ll> ans;
    while (best[n].size()) {
        ans.pb(best[n].top());
        best[n].pop();
    }
    reverse(ans.begin(), ans.end());
    for (auto a: ans)
        cout << a << " ";
    cout << endl;
}

