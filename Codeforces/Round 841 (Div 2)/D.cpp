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
        int n;
        cin >> n;
        vector<ll> a;
        
        ll it;
        for (int i = 0; i < n; i++){
            cin >> it;
            a.pb(it);
        }
        
        vector<ll> m;
        for (int i = 0; i + 1 < n; i++){
            if (a[i + 1] >= a[i]) {
                continue;
            }
            ll val = a[i] + a[i+1];
            if (val %2 == 0){
                val /= 2;
            } else {
                val /=2;
                val ++;
            }
            m.pb(val);
        }
        if (m.size() == 0) {
            cout << 0 << endl;
        } else {
            sort(m.rbegin(), m.rend());
            ll x = m[0];
            //cout << "X " << x << endl;
            
            bool good = true;
            for (int i = 0; i+1 < n; i++){
                if (abs(a[i] - x) - abs(a[i + 1]-x) > 0) {
                    good = false;
                    break;
                }
            }
            if (!good){
                cout << -1 << endl;
            } else {
                cout << x << endl;
            }
        }
        
    }
        
        
    
    return 0;
}
