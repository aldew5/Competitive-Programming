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
    int t;
    cin >> t;
    
    // compute powers of two up to 29
    ull num = 2;
    vector<string> p = {"1", "2"};
    for (int i = 0; i < 60; i++){
        num *= 2;
        p.push_back(to_string(num));
    }
    while (t--) {
        string s;
        cin >> s;
        
        int ans = MX;
        for (int i= 0; i < p.size(); i++){
            
            int del = 0;
            int index = 0;

            // check how many digits are the same
            for (int j = 0; j < s.size() && index < p[i].size(); j++){
                if (p[i][index] != s[j]) {
                    while (j < s.size()) {
                        if (p[i][index] == s[j]){
                            break;
                        }
                        del ++;
                        j ++;
                    }
                }
                index ++;
            }
          
            // number how to delete plus difference in size
            ans = min(ans, del + abs(int(s.size() - del - p[i].size())));
            
        }
        cout << ans << endl;
        
        
    }
}
