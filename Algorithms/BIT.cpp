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
