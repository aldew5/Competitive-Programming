/*
ID: alec3
LANG: C++14
PROG:
*/
/*
We need to find the greatest subarray such that the
sum of the subarray doesn't exceed t.
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


using namespace std;

int main()
{
    //setIO("homework");
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for (auto& it : a) cin >> it;

    ll ans = 0, cnt = 0, sum = 0;
    int r = 0;
    F0R(i, n){
        while (sum < t && r <= n-1){
            sum += a[r];
            r ++;
            cnt ++;
        }
        if (sum <= t)
            ans = max(cnt, ans);
        else{
            ans = max(cnt-1, ans);
            r--;
            cnt --; sum -= a[r];
        }

        sum -= a[i];
        cnt --;

    }
    cout << ans << endl;



    return 0;
}
