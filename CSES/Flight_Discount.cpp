/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Credit to Stanley Zhong
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
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}


using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = 1e10 + 70;

// a struct to more easily store the all the
// relevant data in the pq
struct Item {
    int node;
    ll cost;
    bool discount;

    // constructor
    Item(int _node, ll _cost, bool _discount) {
        node = _node;
        cost = _cost;
        discount = _discount;
    }

    inline const bool operator<(const Item& other) const {
        // if the discounts are the same we compare
        // the costs, otherwise we compare the discounts
        if (discount == other.discount)
            return cost > other.cost;
        return discount > other.discount;
    }
};


vector<pair<ll, ll> > adj[100001];
ll dist[100001][2];

int main()
{
    int n, m;
    cin >> n >> m;
    // read input
    for (int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].emplace_back(b, c);
    }

    // init dist
    for (int i=  0; i < n; i++){
        dist[i][0] = 1e18;
        dist[i][1] = 1e18;
    }

    priority_queue<Item> pq;
    // initial item is node 0, has zero cost
    // and we won't use the discount on it
    pq.emplace(0, 0, false);

    // run dijkstra
    while (pq.size()){
        // get the current item
        Item cur = pq.top();
        pq.pop();

        // we are on the last node and we've used the
        // discount.  Print the cost
        if (cur.node == n-1 && cur.discount){
            cout << cur.cost << endl;
            return 0;
        }

        // for all the cities that cur connects to
        for (auto i : adj[cur.node]){
            // the distance to the next node with either the
            // discount/not the discount is greater
            // than the current cost + cost of the next flight
            if (dist[i.ff][cur.discount] > cur.cost + i.ss){
                // new shortest route
                dist[i.ff][cur.discount] = cur.cost + i.ss;

                // add the next destination to the pq
                pq.emplace(i.ff, dist[i.ff][cur.discount], cur.discount);
            }
            // we aren't using a discount
            if (!cur.discount){
                // the cost of using the discount is greater than the cost of this flight + half the
                // cost of the next flight
                if (dist[i.ff][true] > cur.cost + i.ss /2) {
                    // if we use the discount this is the result
                    dist[i.ff][true] = cur.cost + i.ss /2;
                    // we use the discount.  Add the node
                    pq.emplace(i.ff, dist[i.ff][true], true);
                }
            }
        }
    }

    return 0;
}
