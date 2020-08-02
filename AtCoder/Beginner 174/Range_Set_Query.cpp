/*
ID: alec3
LANG: C++14
PROG: concom
*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define FOR(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

ifstream fin("concom.in");
ofstream fout("concom.out");
const int N = 2e6 + 1;
int n, q;
int c[N], p[N], f[N], ans[N], lz[N];
vector<pair<int, int> > qr[N];

// add elements to lz
void push(int id){
    lz[id * 2] += lz[id];
    lz[id * 2 + 1] += lz[id];
    lz[id] = 0;
}
void upd(int id, int l, int r, int ql, int qr, int v){
    //
    if (l > qr || r < ql)
        return;
    if (ql <= l && r <= qr){
        lz[id] += v;
        return;
    }

    push(id);
    int mid = (l + r) /2;
    upd(id * 2, l, mid, ql, qr, v);
    upd(id * 2 + 1, mid + 1, r, ql, qr, v);
}

int qry(int id, int l, int r, int p){
    if (l == r)
        return lz[id];
    push(id);
    int mid = (l + r) /2;
    if (p <= mid)
        return qry(id * 2, l, mid, p);
    else
        return qry(id * 2 +1, mid + 1, r, p);

}

int main()
{
    io;
    cin >> n >> q;
    // store the values in c
    for (int i = 1; i <= n; i++){
        cin >> c[i];
        // store 
        p[i] = f[c[i]];
        // store index
        f[c[i]] = i;
    }
    for (int i = 1; i <= q; i++){
        int l, r;
        cin >> l >> r;
        // store queries
        qr[r].push_back({l, i});
    }
    // update with each p[i]
    for (int i = 1; i <= n; i++){
        // update
        upd(1, 1, n, p[i] + 1, i, 1);
        // query the array
        for (auto c : qr[i]){
            ans[c.ss] = qry(1, 1, n, c.ff);
        }
    }
    //output
    for (int i = 1; i <= q; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
