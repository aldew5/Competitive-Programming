/*
ID: alec3
LANG: C++14
PROG: ttwo
*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define FOR(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

ifstream fin("ttwo.in");
ofstream fout("ttwo.out");

int grid[11][11];
int main()
{
    char it;
    pair<pair<int, int>, int> f, c;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            fin >> it;
            if (it == '.')
                grid[i][j] = 1;
            else if (it == 'F'){
                f.ff = {i, j};
                f.ss = 0;
                grid[i][j] = 1;
            }
            else if (it == 'C'){
                c.ff = {i, j};
                f.ss = 0;
                grid[i][j] = 1;
            }
            else
                grid[i][j] = 0;

        }
    }
    int ans = -1;
    for (int i = 0; i < 160000; i++){
        if (f.ss == 0){
            if (f.ff.ff -1 >= 0 && grid[f.ff.ff -1][f.ff.ss])
                f.ff.ff --;
            else
                f.ss = 1;
        }
        else if (f.ss == 3){
            if (f.ff.ss -1 >= 0 && grid[f.ff.ff][f.ff.ss - 1])
                f.ff.ss --;
            else
                f.ss = 0;
        }
        else if (f.ss == 2){
            if (f.ff.ff +1 < 10 && grid[f.ff.ff +1][f.ff.ss])
                f.ff.ff ++;
            else
                f.ss = 3;
        }
        else {
            if (f.ff.ss + 1 < 10 && grid[f.ff.ff][f.ff.ss + 1]){
                f.ff.ss ++;
            }
            else
                f.ss = 2;
        }

        if (c.ss == 0){
            if (c.ff.ff - 1 >= 0 && grid[c.ff.ff - 1][c.ff.ss])
                c.ff.ff --;
            else
                c.ss = 1;
        }
        else if (c.ss == 3){
            if (c.ff.ss -1 >= 0 && grid[c.ff.ff][c.ff.ss - 1])
                c.ff.ss --;
            else
                c.ss = 0;
        }
        else if (c.ss == 2){
            if (c.ff.ff +1 < 10 && grid[c.ff.ff +1][c.ff.ss])
                c.ff.ff ++;
            else
                c.ss = 3;
        }
        else {
            if (c.ff.ss + 1 < 10 && grid[c.ff.ff][c.ff.ss + 1]){
                c.ff.ss ++;
            }
            else
                c.ss = 2;
        }

        if (c.ff.ff == f.ff.ff && c.ff.ss == f.ff.ss){
            ans = i + 1;
            break;
        }

        //cout << "ITER " << i << endl;
        //cout << "FARMER " << f.ff.ff << " " << f.ff.ss << " " << f.ss << endl;
        //cout << "COW " << c.ff.ff << " " <<  c.ff.ss << " " << c.ss << endl;
    }
    if (ans == -1)
        fout << 0 << endl;
    else
        fout << ans << endl;

    return 0;
}
