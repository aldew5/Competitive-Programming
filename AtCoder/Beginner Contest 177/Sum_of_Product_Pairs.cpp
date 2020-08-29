/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Just use the ModInt struct to take care of the mod
operations and compute the sum exactly as is stated by the
problem.
*/


#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ld long double
#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

//ifstream fin("maze1.in");
//ofstream fout("maze1.out");
template< int mod >

struct ModInt {
    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt& operator+=(const ModInt& p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt& operator-=(const ModInt& p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt& operator*=(const ModInt& p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt& operator/=(const ModInt& p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt& p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt& p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt& p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt& p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt& p) const { return x == p.x; }

    bool operator!=(const ModInt& p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream& operator<<(ostream& os, const ModInt& p) {
        return os << p.x;
    }

    friend istream& operator>>(istream& is, ModInt& a) {
        int64_t t;
        is >> t;
        a = ModInt< mod >(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

using mint = ModInt< 1000000007 >;


int main()
{
    int n;
    cin >> n;
    mint sum = 0;
    mint sumsq = 0;
    for (int i = 0; i < n; i++) {
        mint x;
        cin >> x;
        sum += x;
        sumsq += (x * x);
    }
    cout << (sum * sum - sumsq) / 2 << endl;

}
