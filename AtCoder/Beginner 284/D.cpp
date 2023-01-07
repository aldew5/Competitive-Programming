// Aldew
 
 
 
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
 
 
#define line cout << "--------------------" << endl;
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define vll vector<ll>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
 
typedef long long ll;
typedef unsigned long long ull;
 
int pct(int x) { return __builtin_popcount(x); }
 
using namespace std;
 
const ll INF = 1e10 + 70;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
 

void solve() {
    ll n;
    cin >> n;
    for (ll i = 2; i*i*i <= n; i++){
        if (n % (i * i) == 0) {
            cout << i << " " << (n/ (i *i)) << endl;
            return;
        } else if (n % i == 0){
            ll v= sqrt(n/i) + 0.1;
            if (v*v*i == n){
                cout << v << " " << i << endl;
                return;
            }
        }
    }
}
 
int main() {
    int T;
    cin >> T;
    while (T --) {
        solve();
    }
 
    return 0;
 }
