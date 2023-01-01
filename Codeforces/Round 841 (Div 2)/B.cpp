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
    while (T--){
        ll n;
        cin >> n;
    
        ll ans = (n * (n+1) % MOD * (2* n+1)% MOD*(MOD+1)/3% MOD+ MOD -n*(n+1)/2% MOD)% MOD;
        ans = ans * 2022 % MOD;
        cout << ans << endl;
    }
    
    return 0;
}
