
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

const ll MOD = 1e9 + 7;
const ll INF = 1e10 + 70;
const ll MX = 2 * 1e6;

ll bit[MX];
vector<int> vals;
int n, q;

void upd(int i, int val){
    for (; i <= MX; i+= i&(-i)){
        bit[i] += val;
    }
}

void add (int x, int val){
    int ind = upper_bound(vals.begin(), vals.end(), x) - vals.begin();
    upd(ind, val);
}

ll sum (int x){
    ll res = 0;
    for (; x; x -= x&(-x)){
        res += bit[x];
    }
    return res;
}

ll query(int x){
    int ind = upper_bound(vals.begin(), vals.end(), x) - vals.begin();
    return sum(ind);
}


int main()
{
    cin >> n >> q;
    vector<int> a(n);
    for (auto& it : a) cin >> it;

    vals = a;
    char x;
    ll y, z;

    vector<pair<int, pair<int, int>> > queries;
    for (int i = 0; i < q; i++){
        cin >> x >> y >> z;
        if (x == '!')
            vals.pb(z);
        queries.pb({x == '?', {y, z}});
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (int i = 0; i < n; i++)
        add(a[i], 1);

    for (auto u : queries){
        u.ss.ff --;
        if (!u.ff){
            add(a[u.ss.ff], -1);
            a[u.ss.ff] = u.ss.ss;
            add(a[u.ss.ff], 1);
        }
        else {
            cout << query(u.ss.ss) - query(u.ss.ff) << endl;
        }
    }


    return 0;
}

