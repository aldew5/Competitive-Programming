
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

// THIS IS A RANGE QUERY ON THE BIT
int query (int i) {
	int res = 0;
	for (; i; i -= (i & (-i))) {
		res = (res + bit[i]) % MOD;
	}
	return res;
}


ll cnt[100001];

int main()
{
    setIO("haircut");
    cin >> n;
    int a;
    for (int i = 0; i< n; i++){
        cin >> a;
        // cnt[a + 1] += the number of hairs before it - sum of all the 
        // frequencies of the elements shorter than a
        // this gives the number of hairs longer than it 
        // and before it
        // which is the number of inversions
        
        cnt[a+1] += i - query(a + 1);
        // update the frequency of a
        upd(a+1, 1);
    }

    // output
    ll ans = 0;
    for (int j = 1; j <= n; j++){
        cout << ans << endl;
        ans += cnt[j];
    }

}

