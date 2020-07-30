/*
ID: alec3
LANG: C++14
PROG: concom
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

ifstream fin("concom.in");
ofstream fout("concom.out");

// company and how much they own of another
int owns[101][101];
// which companies the company controls
int controls[101][101];

// updates the controls array
void addcontroller(int i, int j){
    // already added owner
    if (controls[i][j])
        return;

    // i controls j
    controls[i][j] = 1;

    // add js ownerships to i
    for (int k = 0; k < 101; k++){
        owns[i][k] += owns[j][k];
    }

    // update the companies that control i (if there are any)
    for (int k = 0; k < 101; k++){
        if (controls[k][i])
            addcontroller(k, j);
    }

    // check if i now controls any new companies
    // recursing will update controls and then
    // update the newly controlled companies and continue to recurse
    // until all companies have been updated
    for (int k = 0; k < 101; k++){
        if (owns[i][k] > 50)
            addcontroller(i, k);
    }
}

// updates the percentages all companies that own i
// (including i) and then looks for new controllers
void addowner(int i, int j, int p){

    // add control to each controller
    // of i
    for (int k = 0; k < 101; k++){
        if (controls[k][i])
            owns[k][j] += p;
    }

    // check if any new companies control j
    for (int k = 0; k < 101; k++){
        if (owns[k][j] > 50)
            addcontroller(k, j);
    }
}

int main()
{
    int n;
    fin >> n;

    // every company controls itself
    for (int i = 0; i < 101; i++)
        controls[i][i] = 1;

    int a, b, p;
    for (int i = 0; i < n; i++){
        fin >> a >> b >> p;
        addowner(a, b, p);
    }

    for (int i = 0; i < 101; i++){
        for (int j = 0; j < 101; j++){
            // not the same company and i controls j
            if (i != j && controls[i][j])
                fout << i << " " << j << endl;
        }
    }

    return 0;
}
