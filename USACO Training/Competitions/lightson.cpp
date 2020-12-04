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

bool visit[101][101];
int n, m;
map<pair<int, int>, vector<pair< int, int > > > mp;

int ans = 0;
void flood(int x, int y){
    if (visit[x][y])
        return;
    visit[x][y] = true;
    ans ++;

    for (int i = 0; i < mp[{x, y}].size(); i++){
        if (!visit[mp[{x,y}][i].ff][mp[{x,y}][i].ss])
            flood(mp[{x,y}][i].ff, mp[{x,y}][i].ss);
    }
}



int main()
{
    
    setIO("lightson");
    cin >> n >> m;
    int a, b, c, d;

    for (int i = 0; i < m; i++){
        cin >> a >> b >> c >> d;
        mp[{a, b}].pb({c,d});

    }

    flood(1, 1);

    cout << ans << endl;



    return 0;
}
