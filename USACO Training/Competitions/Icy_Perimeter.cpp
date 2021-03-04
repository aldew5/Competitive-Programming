/*
ID: alec3
LANG: C++14
PROG: perimeter
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

ifstream fin("perimeter.in");
ofstream fout("perimeter.out");
int n;
char grid[1001][1001];
bool visit[1001][1001];

int a, p;
// flood fill that updates perimeter and area for 
// each new block
void ff (int r, int c){
    if (r >= n || c >= n || r < 0 || c < 0 || grid[r][c] == '.' )
        return;

    if (visit[r][c]){
        return;
    }
    a ++;
    visit[r][c] = true;
    int co = 0;
    if (r + 1 < n && grid[r + 1][c] == '.' || r + 1 >= n)
         p++;
    if (r -1 >= 0 && grid[r -1][c] == '.' || r - 1 < 0)
        p ++;;
    if (c + 1 < n && grid[r][c + 1] == '.' || c + 1 >= n)
        p ++;
    if (c -1 >= 0 && grid[r][c-1] == '.' || c -1 < 0)
        p ++;

    ff(r + 1, c);
    ff(r -1, c);
    ff(r, c + 1);
    ff(r, c -1);

    return;

}

int main()
{
    fin >> n;
    FOR (i, 0, n){
        FOR(j, 0, n){
            fin >> grid[i][j];
        }
    }

    int mxa = 0, mxp = 0;
    FOR (i, 0, n){
        FOR(j, 0, n){
            // call flood fill on each disjoint set of # blocks
            if (grid[i][j] == '#' && !visit[i][j]){
                a = 0; p = 0;
                ff(i, j);
                // test if a new max area was found
                if (a >= mxa){
                    // update maxp and maxa
                    if (mxp != 0 && mxa == a)
                        mxp = min(p, mxp);
                    else
                        mxp = p;
                    mxa = a;

                }
            }
        }
    }
    // output
    fout << mxa << " " << mxp << endl;

    return 0;
}
