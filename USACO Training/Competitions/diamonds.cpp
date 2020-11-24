/*
ID: alec3
LANG: C++14
PROG:
/*
We need to find the max value at each left coordinate
if we are picking sets from either side of that coordinate.

We can do this with two pointers and stored values in corrosponding
arrays.
*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" " << endl;
#define line cout << "--------------" << endl;
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ld long double
#define mp make_pair

#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, n) for (int i = 0; i < n; i++)


typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}

template<class T, int SZ> struct PrefixSums {
    T sum[SZ][SZ];
    PrefixSums () { memset(sum,0,sizeof sum); }
    // 2D prefix sum
    void init() {
        FOR(i,1,SZ) FOR(j,1,SZ)
        sum[i][j] += sum[i][j-1]
        +sum[i-1][j]-sum[i-1][j-1];
    }
    // get the sum for a given range
    T get(int X1, int X2, int Y1, int Y2) {
        return sum[X2][Y2]-sum[X1-1][Y2]
        -sum[X2][Y1-1]+sum[X1-1][Y1-1];
    }
};

int main()
{
    setIO("diamond");
    ll n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& it : a) cin >> it;

    sort(all(a));

    int canTakeLeft[n];
    int l = 0, r = 0;
    for (; l < n; l++) {
        // increment r as far as it can go
        while (r < n && a[r] - a[l] <= k)
            r++;
        // when l is (l) we can push r to r - 1
        canTakeLeft[l] = r - l;
    }

    int maxValAfter[n+1];
    maxValAfter[n] = 0;

   for (int i = n-1; i >= 0; i--) {
        // the max value we can obtain by picking left from i
        // is maxvalAfter[i].  The sum of the maxValAfter starting
        // at i + 1 and the max left value
        maxValAfter[i] = max(maxValAfter[i+1], canTakeLeft[i]);
    }

    int ans = 0;
    for (int l = 0; l < n; l++) {
        // max value is the amount we can take from left +
        // maxValAfter starting from cantakeleft[l] + l
        ans = max(ans, canTakeLeft[l] + maxValAfter[l + canTakeLeft[l]]);
    }
    cout << ans << endl;



    return 0;
}
