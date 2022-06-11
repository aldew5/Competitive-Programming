/*
ID: alec3
LANG: C++14
PROG: Counting Rooms
*/
/*

*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" " << endl;
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ld long double
#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define line cout << "--------------" << endl;

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

ifstream fin(".in");
ofstream fout(".out");

int n, m;
char grid[1001][1001];
bool visit[1001][1001];

void flood_fill(int r, int c){
    if (r >= n || c >= m || grid[r][c] == '#' || r < 0 || c < 0)
        return;
    if (visit[r][c])
        return;
    visit[r][c] = true;

    flood_fill(r + 1, c);
    flood_fill(r -1, c);
    flood_fill(r, c + 1);
    flood_fill(r, c -1);

    return;
}


int main()
{
    cin >> n >> m;
    FOR (i, 0, n){
        FOR (j, 0, m){
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    FOR(i, 0, n){
        FOR(j, 0, m){
            if (grid[i][j] != '#' && !visit[i][j]){
                ans ++;
                flood_fill(i, j);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
