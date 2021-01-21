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
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}


using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = 1e10 + 70;

template<class T> struct Seg {
    int n;
    T ID = 0;
    vector<T> seg;
    T comb (T a, T b) {return a + b;}
    void init (int _n) {n = _n; seg.assign(n * 2, ID);}
    void pull (int p) {
        seg[p] = comb(seg[p * 2], seg[p * 2 + 1]);
    }
    void upd (int i, T val) {
        seg[i+=n] += val;
        for (i /= 2; i; i /= 2) {
            pull(i);
        }
    }
    T query (int l, int r) {
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra, seg[l++]);
            if (r&1) rb = comb(rb, seg[--r]);
        }
        return comb(ra, rb);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;

    Seg<ll> seg;
    seg.init(n+2);
    ll ar[n + 1] = {};

    ll it;
    for (int i = 1; i <= n; i++){
        cin >> it;
        // store the original values in an array
        ar[i] = it;
    }

    F0R(i, q){
        int t, a, b, c;
        cin >> t;

        if (t == 1){
            cin >> a >> b >> c;
            // set the value at a to c
            seg.upd(a, c);
            // subtract c from position b + 1
            seg.upd(b + 1, -c);
        }
        else {
            cin >> a;
            // the original value + the first a values
            cout << ar[a] + seg.query(1, a) << endl;
        }
    }


    return 0;
}
