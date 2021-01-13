/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Credit to Oscar Garries

DSUs store different sets as components and can tell which set an
element is in. They can be used to combine any two sets.
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

struct DSU {
    vector<int> e;
    void init (int n) { e = vector<int> (n, -1); }
    int get (int x) { return (e[x] < 0 ? x : e[x] = get(e[x])); }
    bool sameSet (int x, int y) { return get(x) == get(y); }
    int size (int x) { return -e[get(x)]; }
    bool unite (int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};


int main()
{
    int n, m; cin >> n >> m;
    DSU dsu;
    // initialize a DSU of size n
    dsu.init(n);

    int s = n, mx = 1;

    int x, y;
    // loop through queries
    while (m--){
        cin >> x >> y;
        x--; y--;
        // unite the components
        if (dsu.unite(x, y)){
            // the new greatest component size is potentially
            // the new combined component x
            mx = max(mx, dsu.size(x));
            // decrease the number of components
            s --;
        }

        //output
        cout << s << " " << mx << endl;
    }


    return 0;
}
