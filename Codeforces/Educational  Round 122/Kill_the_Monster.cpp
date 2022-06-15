
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

int main () {
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--){
        ll hc, dc;
        ll hm, dm;
        cin >> hc >> dc;
        cin >> hm >> dm;
    
        ll k, w, a;
        cin >> k >> w >> a;

        ll health = hc;
        ll damage = dc;
        bool good = false;

        for (int i = 0; i <= k; i++){
            damage += w * i;
            health += (k-i) * a;

            ll a = hm/damage;
            // hits monster can survive
            if (hm % damage != 0 ){
                a ++;
            }
            ll b = health/dm;
            if (health % dm != 0 ){
                b ++;
            }
            
            if (b >= a){
                cout << "YES" << endl;
                good = true;
                break;
            }

            damage = dc;
            health = hc;
        }

        if (!good){
            cout << "NO" << endl;
        }
    }

    return 0;
}
