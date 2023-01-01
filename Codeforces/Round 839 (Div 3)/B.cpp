// Aldew



#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>



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

int main() {
    
    int T;
    cin >> T;
    while (T--) {
        int grid[2][2];
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                cin >> grid[i][j];
            }
        }
        bool good = false;
        for (int i= 0; i < 4; i++){
            int grid2[2][2];
            grid2[0][0] = grid[1][0];
            grid2[0][1] = grid[0][0];

            grid2[1][0] = grid[1][1];
            grid2[1][1] = grid[0][1];
            
            if (grid[0][0] < grid[0][1] && grid[1][0] < grid[1][1] &&
                grid[0][0] < grid[1][0] && grid[0][1] < grid[1][1]) {
                good = true;
                break;
            }
            grid[0][0] = grid2[0][0];
            grid[1][0] = grid2[1][0];

            grid[1][1] = grid2[1][1];
            grid[0][1] = grid2[0][1];

        }
        
        if (good){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    
    return 0;
}
