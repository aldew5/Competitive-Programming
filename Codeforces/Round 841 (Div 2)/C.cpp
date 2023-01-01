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
    
    io;
    
    int T;
    cin >> T;
    while (T--){
        // A number has an odd number of divisors iff it is a perfect square
        // find sequences whose XOR has odd number and subtract those from all possible
        ll n;
        cin >> n;
        vector<ll> a;
        
        ll it;
        for (int i = 0; i < n; i++){
            cin >> it;
            a.push_back(it);
        }
        
        ll val = 0;
        ll curr = 0;
        vector<ll> mp(2*n);
        mp[0] ++;
        
        // loop over a
        for (int i = 0; i < n; i++){
            //update xor
            curr ^= a[i];
            // loop over perfect squares less than 2n
            // the sum of all elements in the list is less than 2n
            for (ll j = 0; j *j < 2 *n; j++){
                
                
                // note that curr ^ (i*i) =  (curr ^ (i *i)) ^ (i*i)
                // we thus get a number n such that n ^ (j*j) = n
                if ((curr ^ (j * j)) < 2 *n){
                    
                    // curr ^ (j *j) is the number of sequences whose XOR is j*j
                    // that we've see so far
                    val += mp[curr ^ (j *j)];
                }
            }
            mp[curr] ++;
            
        }
        ull ans = ((n * (n + 1)) / 2) - val;
        cout << ans << endl;
        
    }
    
    return 0;
}
