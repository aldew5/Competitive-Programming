/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Credit to Óscar Garries

Since we only need the connected videos to have a min relavance
less than k, we know if two videos have an acceptable relevance
and one of them is in a set, the other can be in that set.

Therefore we can use a DSU where a set represents all the videos
that satisfy a requirement k. We must proces them in increasing relevance
so that we know the requirement is satisfied for all previous videos
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

bool cmp(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b){
    return a.ss.ss > b.ss.ss;
}

int main()
{
    //setIO("closing");

    int n, q;
    cin >> n >> q;
    vector<pair<int, pair<int, int>> > a(n-1);
    for (int i = 0; i < n-1; i++){
        int p, q, r;
        cin >> p >> q >> r;
        p --; q--;
        a[i] = {r, {p, q}};
    }

    // meed to store the query number because
    // we will compute the answers out of order
    vector<pair<int, pair<int, int>>> b(q);
    for (int i = 0 ; i < q; i++){
        int k, v;
        cin >> k >> v;
        v --;
        b[i] = {i, {v, k}};
    }


    // sort them based on the value of k
    sort(b.begin(), b.end(), cmp);
    // sort in decreasing value of r
    sort(a.begin(), a.end(), greater<pair<int, pair<int, int>>>());

    // construct a dsu
    DSU dsu;
    // of size n
    dsu.init(n);
    vector<int> ans(q);

    int index = 0;
    // loop through the queries (sorted by k)
    for (auto query: b){
        // get the video
        int v = query.ss.ff;
        // current value of k
        int curK = query.ss.ss;

        // as long as r is less than the current k
        // unite the videos in the set
        while (index < a.size() && a[index].ff >= curK){
            // unite the first video at the index and the second video
            // since we only care about the min relevance
            // we know all the videos in the united set will satisfy the requirement
            // that k imposes
            dsu.unite(a[index].ss.ff, a[index].ss.ss);
            index ++;
        }
        // the size of the set
        ans[query.ff] = dsu.size(v) -1;
    }
    // output
    for (auto i : ans)
        cout << i << endl;



    return 0;
}
