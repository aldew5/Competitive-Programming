/*
ID: alec3
LANG: C++14
PROG:
/*
Credit to Ben Qi
What a stupid problem
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

int n;
char grid[21][21];
int comp[20][20], temp = 1;
int x1, x2, y11, y2;
int xdir[4] = {1,0,-1,0}, ydir[4] = {0,1,0,-1};
vector<pair<pair<int, int>, pair<int, int> > > ans;

void run(int i, int j) {
    comp[i][j] = temp;
    F0R(it, 4){
        int nx = i + xdir[it], ny = j + ydir[it];
        if (x1 <= nx && nx <= x2 && y11 <= ny && ny <= y2)
            if (comp[nx][ny] == 0 && grid[nx][ny] == grid[i][j])
                run(nx, ny);
    }
    temp ++;
}

bool flood() {
    set<char> c;
    map<char, int> ncomp;

    FOR(i, x1, x2 + 1){
        FOR (j, y11, y2 + 1){
            comp[i][j] =  0;
            c.insert(grid[i][j]);
            if (c.size() > 2)
                return 0;
        }
    }
    if (c.size() == 1)
        return 0;
    FOR (i, x1, x2+1){
        FOR (j, y11, y2 + 1){
            if (comp[i][j] == 0){
                run(i, j);
                ncomp[grid[i][j]] ++;
            }
        }
    }
    vector<int> z;
    for (auto a: ncomp) z.pb(a.ss);

    if (z[0] > z[1])
        swap(z[0], z[1]);
    if (z[0] > 1)
        return 0;
    if (z[1] == 1)
        return 0;
    return 1;

}


bool ok() {
    for (auto z : ans){
        if (z.ff.ff <= x1 && x2 <= z.ff.ss){
            if (y11 >= z.ss.ff && z.ss.ss >= y2)
                return 0;
        }

    }
    return 1;
}

int main()
{
    setIO("where");
    cin >> n;
    for (int j = n-1; j >= 0; j--){
        F0R(i, n) cin >> grid[i][j];
    }
    for (int a = n; a >= 1; a--){
        for (int b = n; b >= 1; b--){
            F0R(c, n-a+1){
                F0R(d, n-b +1){
                    x1 = c; x2 = c+a-1, y11 = d, y2 = d+b-1;

                    if (flood() && ok())
                        ans.pb({{x1, x2}, {y11,  y2}});
                }

            }
        }
    }
    cout << ans.size() << endl;

    return 0;
}
