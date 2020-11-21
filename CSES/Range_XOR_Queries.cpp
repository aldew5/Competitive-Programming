/*
ID: alec3
LANG: C++14
PROG:
/*
No seg tree :)
*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" " << endl;
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ld long double
#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define line cout << "--------------" << endl;

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
    //setIO("measurement");
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1);
    for (int i = 1; i < n+1; i++){
        cin >> a[i];
        a[i] ^=a[i-1];
    }

    ll x, y;
    FOR (i, 0, q){
        cin >> x >> y;
        cout << (a[y] ^ a[x-1]) << endl;
        //cout << "AFTEr " << pre[y] << " " << pre[x-1] << endl;
    }

    return 0;
}
