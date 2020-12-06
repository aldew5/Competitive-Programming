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


int main()
{
    int n; cin >> n;
    ll a, d;

    vector<pair<ll, ll> > v;

    F0R(i, n){
        cin >> a >> d;
        v.pb({a, d});
    }
    sort(v.begin(), v.end());

    ll time = 0;
    ll ans = 0;
    F0R(i, v.size()){
        ans += v[i].ss - (time + v[i].ff);
        time += v[i].ff;
    }

    cout << ans << endl;
    return 0;
}
