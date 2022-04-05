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

void union_init(int d[], int s) { for (int i=0; i < s; i++) d[i]=i; }
int union_query(int d[], int n) { int res=n; while (d[res]!=res) res=d[res]; int m; while (d[n]!=n) {m=d[n];d[n]=res;n=m;} return res; };
int union_merge(int d[], int x, int y) { x=union_query(d,x); y=union_query(d,y); if (x==y)return -1; d[x]=y; return 1; }
