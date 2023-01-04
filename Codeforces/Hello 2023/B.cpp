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
        // need l and r
        int n;
        cin >> n;
        if (n %2 == 0){
            cout << "YES" << endl;
            int val = 1;
            for (int i = 0; i < n; i++){
                cout << val << " ";
                val *= -1;
            }
            cout << endl;
        } else {
            int val = n/2;
            int x = val;
            int y = -1 * x + x/val;
            
            if (y == 0) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
                for (int i = 0; i < (n-1)/2; i++) {
                    cout << y << " " << x << " ";
                }
                cout << y << endl;
            }
            
            
        }
    }
    return 0;
}
