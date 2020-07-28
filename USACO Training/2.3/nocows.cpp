/*
ID: alec3
LANG: C++14
PROG: nocows
*/
/*
This is a dynamic programming problem that can be solved using
the build things from smaller things paradigm.  
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

ifstream fin("nocows.in");
ofstream fout("nocows.out");

const int MOD = 9901;
// contains the depth and number of nodes of a stree
int table[101][202], n, k, c;
// conotains rees of any depth smaller than i-1
int small[101][202];


int main() {
    int n, k;
    fin >> n >> k;

    // there is only one way to make a tree of size one
    table[1][1] = 1;
    // loop through different depths
    for (int i = 2; i <= k; i++){
        // different numbers of nodes
        for (int j = 1; j <= n; j += 2){
            // number of nodes in the left subtree
            // j -1-k is the number of nodes in the right subtree
            for (int k = 1; k <= j-1-k; k += 2){

                // if the depths aren't the same we'll add two options
                if (k != j-1-k) c = 2;
                // if they are, there's only one option
                else c = 1;
                // for each of the possibilites there are c choices
                                    // left subtree smaller than i-1, right is i-1
                table[i][j] += c * (small[i-2][k] * table[i-1][j-1-k] +
                                    // left subtree is i-1, right smaller
                                    table[i-1][k] * small[i-2][j-1-k] +
                                    // both i-1
                                    table[i-1][k] * table[i-1][j-1-k]);
                table[i][j] %= MOD;

            }
        }
        for (int w = 0; w <= n; w++){
                // update the smaller trees array
                small[i-1][w] += table[i-1][w] + small[i - 2][w];
                small[i-1][w] %= MOD;
         }
    }
    // output
    fout << table[k][n] << endl;


    return 0;

}
