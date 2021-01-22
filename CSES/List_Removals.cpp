/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Credit to Benq
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
const ll INF = 1e10 + 70;
const ll MX = 2 * 1e6;

constexpr int bits(int x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
    return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x))

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

BIT<int, MX> bit;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto& it : a) cin >> it;
    vector<int> p(n);
    for(auto& it : p) cin >> it;

    for (int i = 1; i<= n; i++){
        bit.upd(i, 1);
    }

    for (auto i : p){
        int index = get_kth(bit, i);
        cout << a[index-1] << " ";
        bit.upd(index, -1);
    }

    return 0;
}
