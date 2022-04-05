struct BIT {
    vector<long long> bit;
    int n;

    // init with zeros
    BIT(int n){
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    BIT (vector<long long> a) : BIT(a.size()){
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    // sum up to r
    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    // update an index
    void add(int idx, int val) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += val;
    }

    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }

    int point_query(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
};


// simple vector
const int MX = 2e5+5;

int n, q;
vector<ll> bit(MX), x(MX);

void upd(int i, ll v) {
    for (; i<=n; i+=i&(-i)) bit[i]+=v;
}

ll qry(int i) {
    ll sum = 0;
    for(; i>0; i-=i&(-i)) sum += bit[i];
    return sum;
}

// template
template <class T, int ...Ns> struct BIT {
    T val = 0; void upd(T v) { val += v; }
    T query() { return val; }
};
template <class T, int N, int... Ns> struct BIT<T, N, Ns...> {
    BIT<T,Ns...> bit[N+1];
    template<typename... Args> void upd(int pos, Args... args) { assert(pos > 0);
        for (; pos<=N; pos+=pos&-pos) bit[pos].upd(args...); }
    template<typename... Args> T sum(int r, Args... args) {
        T res=0; for (;r;r-=r&-r) res += bit[r].query(args...); 
        return res; }
    template<typename... Args> T query(int l, int r, Args... 
        args) { return sum(r,args...)-sum(l-1,args...); }
}; 
template<class T, int N> int get_kth(const BIT<T,N>& bit, T des) { 
    assert(des > 0);
    int ind = 0;
    for (int i = 1<<bits(N); i; i /= 2)
        if (ind+i <= N && bit.bit[ind+i].val < des)
            des -= bit.bit[ind += i].val;
    assert(ind < N); return ind+1;
}
