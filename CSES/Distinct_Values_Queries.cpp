
/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Credit to Benq
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
const ll MX = 4e5 + 5;

void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}



int bit[MX];
int n, q, sol[MX];
vector<pair<int, int>> query[MX];
vector<int> x(MX);
map<int, int> fst;

int qry (int i) {
    int res = 0;
    for (; i; i -= i&(-i)) {
        res += bit[i];
    }
    return res;
}

void upd (int i, int val) {
    for (; i <= n; i += i&(-i)) {
        bit[i] += val;
    }
}



int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }
    // bit is initially all zeros
    for (int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        // final and the query index (we wil answer out of order)
        query[a].pb(make_pair(b, i));
    }

    // loop through i from high to low
    for (int i= n; i >= 1; i--){
        // z is the value of x at i (zero-indexed)
        int z = x[i-1];

        // if we've seen this number before
        if (fst.count(z))
            // subtract one from the ith value of the bit
            upd(fst[z], -1);
        // save the index of the number z as i
        fst[z] = i;
        // increment the ith index
        upd(i, 1);
        for (auto t : query[i]){
            // we will be adding zeros and ones in the query
            sol[t.ss] = qry(t.ff);
        }
    }
    for (int i = 0; i < q; i++)
        cout << sol[i] << endl;


}

