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

struct Cow {
    int x, y, power;
};

int visit[201];
vector<Cow> a;

void dfs(int n){
    if (visit[n]){
        //cout << "HERE" << endl;
        return;
    }

    visit[n] = true;

    for (int i = 0; i < a.size(); i++){
        if (a[n].power * a[n].power >= (a[i].x - a[n].x)*(a[i].x - a[n].x) + (a[i].y - a[n].y)* (a[i].y - a[n].y))
            dfs(i);
    }

}


using namespace std;

int main()
{
    setIO("moocast");
    int n;
    cin >> n;

    int x, y, z;
    for (int i = 0; i < n; i++){
        cin >> x >> y >> z;
        Cow c;
        c.x = x; c.y = y; c.power = z;
        a.pb(c);
    }

    int ans = 0;
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j <= 200; j++)
            visit[j] = false;
        dfs(i);

        int cnt = 0;
        for (int i = 0; i <= 200; i++)
            cnt += visit[i];

        ans = max(ans, cnt);
    }
    cout << ans << endl;



    return 0;
}
