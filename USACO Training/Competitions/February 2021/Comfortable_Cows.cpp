

#include <bits/stdc++.h>
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

const ll INF = 1e10 + 70;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;

vector<pair<int, int> > val;
int grid[5000][5000];

int tot = 0;
void check(int i, int j){

    int cnt = 0;
    pair<int, int> a;

    if (grid[i][j] == 1){
        cnt = 0;
        cnt += grid[i + 1][j];
      
        if (grid[i +1][j] == 0)
            a = {i + 1, j};

        if (i != 0){
            cnt += grid[i-1][j];
            if (grid[i-1][j] == 0)
                a = {i-1, j};
        }

        cnt += grid[i][j + 1];
        if (grid[i][j +1] == 0)
            a = {i, j + 1};
     
        if (j != 0){
            cnt += grid[i][j-1];
            if (grid[i][j-1] == 0)
                a = {i, j -1};
        }
   

    }
    if (cnt == 3){
        tot ++;
        grid[a.ff][a.ss] = 1;
        check(a.ff, a.ss);
        if (a.ff > 0)
            check(a.ff-1, a.ss);
        if (a.ss > 0)
            check(a.ff, a.ss-1);
        check(a.ff + 1, a.ss);
        check(a.ff, a.ss + 1);
    }

    return;
}

int main()
{
    io;
    int n;
    cin >> n;
    int a, b;

    vector<pair<int, int>> c;
    vector<int> ans;

    for (int i = 0; i < n; i++){
        cin >> a >> b;
        a += 1000; b += 1000;

        if (grid[a][b] == 1)
            tot --;

        grid[a][b] = 1;

        check(a, b);
        check(a - 1, b);
        check(a, b-1);
        check(a + 1, b);
        check(a, b + 1);
      
        ans.pb(tot);
    }
    for (auto i : ans)
        cout << i << endl;
    return 0;
}
