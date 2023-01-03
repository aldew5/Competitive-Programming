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
        int k, n;
        cin >> k >> n;
        
        vector<int> ans;
        int val = n;
        int incr = 1;
        map<int, int> mp;
        
        while (val > 0) {
            if (ans.size() == k) {
                break;
            }
            mp[val] ++;
            //cout << "val " << val << endl;
            ans.pb(val);
            val -= incr;
            incr ++;
            continue;
        }
        val = 1;
        while (ans.size() < k){
            if (!mp[val]) {
                //cout << "val2  " << val << endl;
                ans.pb(val);
            }
            val ++;
        }
        sort(ans.begin(), ans.end());
        
        
        for (int i= 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
