
/*
ID: alec3
LANG: C++14
PROG:
*/
/*

*/


#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" " << endl;
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

void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}


int bit[MX];
int n;

void upd (int i, int val) {
	for (; i <= n; i += (i & (-i))) {
		bit[i] = (bit[i] + val) % MOD;
	}
}

int query (int i) {
	int res = 0;
	for (; i; i -= (i & (-i))) {
		res = (res + bit[i]) % MOD;
	}
	return res;
}



int main()
{
    cin >> n;
    map<int, int> mp;
    int ar[n];
    for (int i = 0; i< n; i++){
        cin >> ar[i];
        // count each number
        mp[ar[i]] ++;
    }

    int cnt = 0;
    // loop over the map and
    // set each value to the index it's at
    for (auto &it : mp){
        it.ss = ++cnt;
    }

    // set ar[i] to the value that would
    // be at i if the array were sorted
    for (int &x : ar){
  
        x = mp[x];
    }
     

    int ans = 0;
    for (int x : ar){
        // increasing subsequence is 1 + 
        // the number up to but not including x
        int sub = 1 + query(x -1);
        // add the count and compute it mod
        ans = (ans + sub) % MOD;
        // update the xth value to store the number of 
        // new increasing subsequences
        upd(x, sub);
    }
    cout << ans << endl;

}

