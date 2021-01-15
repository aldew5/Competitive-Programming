/*
ID: alec3
LANG: C++14
PROG:
*/
/*
We start from the leftmost cow. For each new cow, if we find it's first choice has been
picked already we switch out the cow who took it. We propagate this switch down the line of cows
until we have a valid solution.
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

int n, m;
ll grid[2002][2002];
bool visited[2002][2002];

vector<pair<ll, ll> > d[1000001];

bool BFS(pair<ll, ll> src, pair<ll, ll> dest){
    //cout << "CALLED " << endl;

    queue<pair<ll,ll> > q;
    q.push(src);


    while (!q.empty()){
        pair<ll, ll> node = q.front();
        q.pop();
       // cout << node.ff << " " << node.ss << endl;
       // cout << grid[node.ff][node.ss] << endl;

        if (node.ff == n && node.ss == m)
            return true;

        if (!visited[node.ff][node.ss]){
            visited[node.ff][node.ss] = true;

            ll val = grid[node.ff][node.ss];
            for (int i = 0; i < d[val].size(); i++){

                q.push(mp(d[val][i].ff, d[val][i].ss));

            }
        }
    }
    return false;

}


int main()
{
    //setIO("fenceplan");
    io;
    cin >> n;
    cin >> m;
    ll it;
    for (int i= 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> it;
            grid[i][j] = it;

            d[i *j].pb(mp(i, j));
        }
    }

    if (BFS({1,1}, {n, m}))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;

}
