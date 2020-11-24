/*
ID: alec3
LANG: C++14
PROG:
/*
Two pointers iterating over the third value
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

int dp[1000][1001];

int main()
{
    io;
    int n, x; cin >> n >> x;
    vector<pair<int, int> > a;

    // read in values and save them with their positions
    for (int i = 1; i <= n; i++){
        int it; cin >> it;
        pair<int, int> p;
        p.ff = it; p.ss = i;

        a.pb(p);
    }

    // sort by value
    sort(a.begin(), a.end());


    for (int i = 0; i < n; i++){
        int l = 0, r = n-1;

        // not same value
        while (l != r){
            // the target sum is the value we're trying to obtain
            // minus the current third value
            int val = x - a[i].ff;
            // both values aren't in the same position and their sum is the val
            if (l != i && r != i && a[l].ff + a[r].ff == val){
                // print out
                cout << a[i].ss << " " << a[l].ss << " " << a[r].ss << endl;
                return 0;
            }
            // to small increase the value of a[l]
            if (a[l].ff + a[r].ff < val)
                l ++;
            // to big decrease the value of a[r]
            else
                r --;
        }
    }
    // didn't find one
    cout << "IMPOSSIBLE" << endl;


    return 0;
}
