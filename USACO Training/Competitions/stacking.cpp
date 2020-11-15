/*
ID: alec3
LANG: C++14
PROG:
*/
/*
0, 0, 0, 0, 0
0, 1, 1, 1, 0 -> 0, 1, 0, 0, -1

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

int main()
{
    setIO("stacking");
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);

    ll x, y;
    FOR(i, 0, k){
        cin >> x >> y;
        a[x] ++;
        if (y + 1 <= n)
            a[y+1] --;
    }

    vector<ll> pre;
    ll s = 0;
    for (int i = 1; i < n + 1; i++){
        s += a[i];
        pre.pb(s);
    }
    sort(pre.begin(), pre.end());

    cout << pre[pre.size()/2 + 1] << endl;


    return 0;
}
