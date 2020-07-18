/*
Aldew (credit to BigBag)
LANG: C++14
PROG: Two Snuke
CLASSIFICATION: math, polynomials
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ifstream fin (".in");
ofstream fout (".out");


/*
Difficult math problem requiring the use of polynomials.
*/
const int max_n = 111, mod = 1000000007;
int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        return power(mul(a, a), b / 2);
    }
    return mul(a, power(a, b - 1));
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

int t, n, a[max_n], b[max_n];
int dp[2][max_n];

void calc_dp(int tp, int a[]) {
    int q1 = 0, q2 = 1;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < max_n; i += 1) {
        dp[q1][i] = 1;
    }
    for (int it = 0; it < 5; ++it) {
        memset(dp[q2], 0, sizeof(dp[q2]));
        for (int n = 0; n < max_n; ++n) {
            for (int x = 0; 2 * x <= n; ++x) {
                for (int d = 1; 2 * x + d <= n; ++d) {
                    dp[q2][n] += mul(d, dp[q1][n - 2 * x - d]);
                    dp[q2][n] %= mod;
                }
            }
        }
        swap(q1, q2);
    }
    copy(dp[q1], dp[q1] + max_n, a);
}

polynom get_polynom(int a[], int tp) {
    vector<int> x, y;
    for (int i = tp; i < max_n; i += 2) {
        x.push_back(i);
        y.push_back(a[i]);
    }
    polynom p = interpolate(x, y);
    return p;
}


int main() {
    io;
    calc_dp(0, a);
    calc_dp(1, b);
    polynom p1 = get_polynom(a, 1);
    polynom p2 = get_polynom(b, 2);

    cin >> t;
    while (t--){
        cin >> n;
        if (n % 2 == 1){
            cout << p1.calculate_at(n) << endl;
        }
        else {
            cout << p2.calculate_at(n) << endl;
        }
    }


    return 0;
}
