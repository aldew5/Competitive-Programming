/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Loop through xs and keep an index of the sorted list of cows,
if the distance is less than x, then add it to the set.
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

struct DSU {
    vector<int> e;
    void init (int n) { e = vector<int> (n, -1); }
    int get (int x) { return (e[x] < 0 ? x : e[x] = get(e[x])); }
    bool sameSet (int x, int y) { return get(x) == get(y); }
    int size (int x) { return -e[get(x)]; }
    bool unite (int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

// dp[i][x][j]
// max wins for the ith move if we switch x times and play j on the ith move
int dp[100001][20][4];
int win[4][4];
int main()
{
    setIO("hps");
    int n, k;
    cin >> n >> k;
    vector<int> a;

    char it;
    // 3 beats 2
    // 2 beats 1
    // 1 beats 3
    win[1][3] = 1;
    win[2][1] = 1;
    win[3][2] = 1;

    for (int i =0; i < n; i++){
        cin >> it;
        if (it == 'P')
            a.pb(1);
        if (it == 'S')
            a.pb(2);
        if (it == 'H')
            a.pb(3);
    }

    // at each turn she could either play what she played last time
    // or switch and decrease the amount of switches she has left
    dp[0][0][1] = 1;
    dp[0][0][2] = 1;
    dp[0][0][3] = 1;

    dp[0][0][a[0]] = 0;
    dp[0][1][a[0]] = 1;


    for (int i = 1; i < n; i++){
        for (int j = 0; j <= k; j++){
            for (int m = 1; m <= 3; m++){

                if (j == 0){
                    dp[i][j][m] = dp[i-1][j][m] + (a[i-1] == m ? 1 : 0);
                    //cout << "J = 0" << " " << i << endl;
                    //cout << "M: " << m << " " << dp[i][j][m] << endl;
                }
                else {
                    int m1, m2;
                    if (m == 1){
                        m1 = 2; m2 = 3;
                    }
                    else if (m == 2){
                        m1 = 1; m2 = 3;
                    }
                    else {
                        m1 = 1; m2 = 2;
                    }

                    // the max between making j switches and picking move m on the i-th move
                    // and not switching
                    dp[i][j][m] = max(max(dp[i-1][j][m], dp[i-1][j-1][m1]), dp[i-1][j-1][m2]) + (a[i-1] == m ? 1 : 0);

                    //cout << "HERE " << i << " " << j << " " << m << endl;
                    //cout << dp[i][j][m] << endl;
                }
            }
        }
        //cout << "HERE " << i << endl;
    }
    //cout << "END" << endl;


    cout << max({dp[n-1][k][1], dp[n-1][k][2], dp[n-1][k][3]}) << endl;



    return 0;
}
