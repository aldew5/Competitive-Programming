
/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Credit to Andrew Wang
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
vector<pair<ll, int>> edge[100001];
ll dist[100001]; ll num[100001];
int minf[100001];int maxf[100001];
bool v[100001];

// modified dj
void djikstra(int s){
    // contain pairs in a vector
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    
    // create the first city
    pair<ll, int> p; p.ff = 0; p.ss = s;
    // add it to the pq
    pq.push(p);
    // distance to s is 0, 1 way to get there
    num[s] = 1; dist[s] = 0;
    
    
    while (!pq.empty()){
        pair<ll, int> cur = pq.top(); pq.pop();
        
        // haven't visited it
        if(!v[cur.second]){
            v[cur.second] = true;
            
            // loop through the cities it's connected to
            for(pair<ll, int> e : edge[cur.second]){
                
                ll cost = e.first; int next = e.second;
                ll alt = cost + dist[cur.second];
                
                // alternate route to the next city is the 
                // same as the min distance to the city
                if(alt == dist[next]){
                    // update the number of ways we can get there
                    num[next] = (num[next] + num[cur.second]) % MOD;
                    // and the max and min flights
                    minf[next] = min(minf[next], minf[cur.second]+1);
                    maxf[next] = max(maxf[next], maxf[cur.second]+1);
                    // get the next city
                    e.first = dist[next];
                    pq.push(e);
                }
                // found a cheaper route
                else if(alt < dist[next]){
                    // update and reset all the values
                    dist[next] = alt;
                    num[next] = num[cur.second];
                    minf[next] = minf[cur.second]+1;
                    maxf[next] = maxf[cur.second]+1;
                    e.first = dist[next];
                    pq.push(e);
                }
            }
        }
    }
}

int main()
{
  io;
  int n, m;
  cin >> n >> m;
  // construct the edges a -> {cost, city}
  for (int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    pair<ll, int> d = {c, b};
    edge[a].pb(d);
  }
    
    // init the arrays 
    for (int i = 0; i < 100001; i++){
        dist[i] = MX;
        num[i] = 0; minf[i] = 0; maxf[i] = 0;
    }
  djikstra(1);
  // output
  cout << dist[n] << " " << num[n] << " " << minf[n] << " " << maxf[n] << endl;

}

