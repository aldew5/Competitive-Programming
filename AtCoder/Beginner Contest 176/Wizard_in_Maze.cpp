/*
ID: alec3
LANG: C++14
PROG:
*/
/*
This is an 0-1 BFS.  
*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ld long double
#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

string s, t;
ll ans = 0;
ll n, m;
bool mat[1005][1005];
bool vis[1005][1005];

ll dr[4] = {0, 0, -1, 1};
ll dc[4] = {1, -1, 0, 0};

// valid position
bool valid(ll r, ll c){
    return r >= 0 && r < n && c >= 0 && c < m;
}


void solve(){
    cin >> n >> m;
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--; c--; d--;
    
    for (ll i = 0; i < n; i++){
        cin >> s;
        for (ll j = 0; j < m; j++){
            mat[i][j] = (s[j] == '.');
        }
    }
    
    deque<pair<pair<ll, ll>, ll>> dq;
    //
    dq.push_front(make_pair(make_pair(a, b), 0));

    while (!dq.empty()){
        pair<pair<ll, ll>, ll> x = dq.front();
        dq.pop_front();

        pair<ll, ll> pos = x.ff;

        if (vis[pos.ff][pos.ss]) continue;
        vis[pos.ff][pos.ss] = 1;

        if (pos.ff == c && pos.ss == d){
            cout << x.ss << endl;
            return;
        }

        for (ll d = 0; d < 4; d++){
            ll nr = pos.ff + dr[d];
            ll nc = pos.ss + dc[d];

            if (valid(nr, nc) && mat[nr][nc] && !vis[nr][nc])
                dq.push_front(make_pair(make_pair(nr, nc), x.ss));
        }

        for (ll dr = -2; dr <= 2; dr++){
            for (ll dc = -2; dc <= 2; dc++){
                ll nr = pos.ff + dr;
                ll nc = pos.ss + dc;

                if (valid(nr, nc) && mat[nr][nc] && !vis[nr][nc])
                    dq.push_back(make_pair(make_pair(nr, nc), x.ss + 1));
            }
        }
    }
    cout << -1 << endl;
    return;

}

int main()
{
    io;
    solve();

    return 0;

}
