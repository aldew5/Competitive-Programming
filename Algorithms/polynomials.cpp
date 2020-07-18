const int mod = MAX_INT;
int mul(int x, int y) {
    return 1LL * x * y % mod;
}

struct polynom {
    int n, coef[max_n];
 
    polynom(int a = 0) {
        memset(coef, 0, sizeof(coef));
        coef[0] = a;
        n = 1;
    }
 
    void multiply(int a) { // multiply by (x - a)
        for (int i = n - 1; i >= 0; --i) {
            coef[i + 1] += coef[i];
            coef[i + 1] %= mod;
            coef[i] = mul(coef[i], mod - a);
        }
        ++n;
    }
 
    void divide(int a) { // divide by (x - a)
        for (int i = n - 1; i > 0; --i) {
            coef[i - 1] += mul(coef[i], a);
            coef[i - 1] %= mod;
        }
        for (int i = 0; i + 1 < n; ++i) {
            coef[i] = coef[i + 1];
        }
        --n;
        coef[n] = 0;
    }
 
    void operator += (const polynom &p) {
        for (int i = 0; i < p.n; ++i) {
            coef[i] += p.coef[i];
            coef[i] %= mod;
        }
        n = max(n, p.n);
    }
 
    polynom operator * (int a) { // multiple by a
        polynom res;
        res.n = n;
        for (int i = 0; i < n; ++i) {
            res.coef[i] = mul(coef[i], a);
        }
        return res;
    }
 
    int calculate_at(int x) {
        int res = 0, pw = 1;
        for (int i = 0; i < n; ++i) {
            res += mul(pw, coef[i]);
            res %= mod;
            pw = mul(pw, x);
        }
        return res;
    }
 
    friend ostream& operator << (ostream &os, const polynom &p) {
        bool was = false;
        for (int i = p.n - 1; i >= 0; --i) {
            if (p.coef[i] == 0) {
                continue;
            }
            if (was) {
                os << " + ";
            }
            was = true;
            if (p.coef[i] != 1 || i == 0) {
                os << p.coef[i];
            }
            if (i && p.coef[i] != 1) {
                os << "*";
            }
            if (i == 1) {
                os << "x";
            } else if (i > 1) {
                os << "x^" << i;
            }
        }
        return os;
    }
};


polynom interpolate(const vector<int> &x, const vector<int> &y) {
    polynom res;
    polynom all_p(1);
    for (int i = 0; i < x.size(); ++i) {
        all_p.multiply(x[i]);
    }
    for (int i = 0; i < x.size(); ++i) {
        int coef = 1;
        for (int j = 0; j < x.size(); ++j) {
            if (j != i) {
                coef = mul(coef, (x[i] + mod - x[j]));
            }
        }
        coef = power(coef, mod - 2);
        coef = mul(coef, y[i]);
        all_p.divide(x[i]);
        res += all_p * coef;
        all_p.multiply(x[i]);
    }
    return res;
}
