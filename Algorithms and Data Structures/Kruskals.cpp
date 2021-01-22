// Kruskal's to find MST with a DSU

// Credit to Benq

struct DSU {
    vi e; void init(int N) { e = vi(N,-1); }
    // get representive component, uses path compression
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) { // union by size
        x = get(x), y = get(y); if (x == y) return 0;
        if (e[x] > e[y]) swap(x,y);
        e[x] += e[y]; e[y] = x; return 1;
    }
};
 
int comp;
template<class T> T kruskal(int N, vector<pair<T,pi>> ed) {
    sort(all(ed));
    T ans = 0; DSU D; D.init(N+1); // edges that unite are in MST
    trav(a,ed)
    if (D.unite(a.s.f,a.s.s)) {
        ans += a.f;
        comp--;
    }
    return ans;
}
