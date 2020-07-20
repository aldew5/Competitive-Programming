/*
ID: alec3
LANG: C++14
PROG: holstein
CLASSIFICATION: math, polynomials
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ifstream fin ("holstein.in");
ofstream fout ("holstein.out");

/*
Greedy solutions don't work! You need to just take advantage of the
fact that there are only a small number of possible combinations
and just try them all.
*/

const int MAXV = 25;
const int MAXF = 15;

int vit[MAXV];
int v;

int feed[MAXF][MAXV];
int g;

int mx;
int res[MAXF];

int curr[MAXF];

void solve(int feedcnt, int first){

    int i;
    for (i = 0; i < v; i++){
        if(vit[i] > 0) break;
    }

    // all requirements were met
    if (i >= v){
        mx = feedcnt;
        for (i = 0; i < mx; i++){
            res[i] = curr[i];
        }
        return;
    }

    while (first < g && feedcnt + 1 < mx){
        /* try adding each feed to the mixture the fcnt+1 <
        mx ensures that we stop if there's no hope
        in finding a better solution than one found already */

        // add the vitamins from this feed type
        for (i = 0; i < v; i++){
            vit[i] -= feed[first][i];
        }
        // add to list
        curr[feedcnt] = first;

        solve(feedcnt + 1, first + 1);

        // we didn't return so undo
        for (i = 0; i < v; i++){
            vit[i] += feed[first][i];
        }
        // try the next one
        first ++;

    }

}

int main() {
    io;
    fin >> v;
    for (int i = 0; i < v; i++){
        fin >> vit[i];
    }
    fin >> g;
    for (int i = 0; i < g; i++){
        for (int j = 0; j < v; j++){
            fin >> feed[i][j];
        }
    }

    mx = g + 1;
    solve(0, 0);

    fout << mx << " ";
    for (int i = 0; i < mx; i++){
        fout << res[i] + 1;
        if (i + 1 != mx) fout << " ";
    }
    fout << endl;

    return 0;
}
