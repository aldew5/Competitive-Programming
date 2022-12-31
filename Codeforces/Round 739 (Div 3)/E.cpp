// Aldew
/*
 binary search on the set of lengths of possible initial strings. Check if a length
 is right by computing the corresponding substring and doing the procedure.
 */

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



string check_string(string s, string poss, string lets) {
    string s2;
    string prev = poss;
    vector<string> v = {poss};
    for (int i = 0; i < lets.size(); i++) {
        s2 = "";
        for (int j = 0; j < prev.size(); j++) {
            if (prev[j] != lets[i]) {
                s2 += prev[j];
            }
        }
        prev = s2;
        v.push_back(s2);
    }
    
    string ans = "";
    for (int i = 0; i < v.size(); i++){
        ans += v[i];
    }
    
    return ans;
}

int main() {
    int t;
    cin >> t;
    
    
    while (t--) {
        string s;
        cin >> s;
        
        map<char, int> m;
        vector<char> c;
        vector<pair<int, char>> v;
        
        for (int i = 0; i < s.size(); i++){
            // haven't seen it
            if (m[s[i]] == 0) {
                c.push_back(s[i]);
            }
            m[s[i]] = i + 1;
        }
        for (int i = 0; i < c.size(); i++){
            v.push_back(make_pair(m[c[i]], c[i]));
        }
        // gives order of disappearances
        sort(v.begin(), v.end());
        string order = "";
        for (int i = 0; i < v.size(); i++){
            //cout << v[i].ff << " " << v[i].ss << " ";
            order += v[i].ss;
        }
        
        // binary search to find length of string
        // valid string
        // - must contain all letters
        // - loop through remove each letter and check
        
        int low = 1;
        int high = int(s.size());
        
        string ans = "";
        string s2;
        int len;
        //cout << "HERE " << order << endl;
        while (low <= high){
            len = (high + low)/2;
            s2 = check_string(s, s.substr(0, len), order);

            if (s2.size() > s.size()){
                high = len - 1;
            } else if (s2.size() < s.size()){
                low = len +1;
            }
            if (s2.size() == s.size()) {
                break;
            }
        }
        if (s2 == s){
            cout << s.substr(0, len) << " " << order << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
