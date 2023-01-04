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
        string s;
        cin >> s;
        
        int l = -1;
        int r = -1;
        for (int i = 0; i < n; i++){
            if (s[i] == 'L') {
                l = i;
            } else if (s[i] == 'R' && r == -1) {
                r = i;
            }
        }
        
        if (r == -1 || l == -1){
            cout << -1 << endl;
        }
        else if (r < l) {
            cout << 0 << endl;
        }
        else {
            if (l +1 == r) {
                cout << l + 1 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}
