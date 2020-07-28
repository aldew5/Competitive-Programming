/*
ID: alec3
LANG: C++14
PROG: prefix
(credit to Benq)
*/


#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define FOR(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

ifstream fin("prefix.in");
ofstream fout("prefix.out");

int dp[200001], ans = 0;
vector<string> pre;

int main() {
	string s, s1;
	// get input
	while (fin >> s1) {
		if (s1 == ".") break;
		pre.pb(s1);
	}
	while (fin >> s1) s += s1;
	
	dp[0] = 1;
	
	// loop throught characters in s
	FOR(i,1,s.length()+1) {
	    // loop through the prefixes
	    for (string k: pre) {
            // possible prefix
            if (k.length() <= i){
                // possible to make the prefix leading up to it and the prefix can be added on
                if (dp[i-k.length()] && s.substr(i-k.length(),k.length()) == k) {
                    // possible
                    dp[i] = 1;
                    // new longest prefix
                    ans = i;
                    break;
                }
            }
	    }
	}
	fout << ans << endl;
}
