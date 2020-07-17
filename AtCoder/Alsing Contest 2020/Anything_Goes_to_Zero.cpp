/*
Aldew (credit to aviroop123)
LANG: C++14
PROG: Anything Goes to Zero
CLASSIFICATION: bit manipulation
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;


int pwr(int a,ll b) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = (ans * 1LL * a);
		a = (a * 1LL * a);
		b >>= 1;
	}
    return ans;
}

/*
The key thing to realize is that each X_i either
has a popcount that is one greater or one less than
the original popcount. Therefore you only have to compute
popcount once and then based on whether the index is 1 or
0 decrease or increase it. This is the only way to solve the
problem in the time limit.
*/

const int N = 2e5 + 5;
int f[N];
int pw[3][N];

void solve(){
    int n;
    cin >> n;
    // loop through all numbers less than the length of s
    for (int i = 1; i <= n; i++){
        // compute the number mod popcount
        int j = i % pct(i);
        // save f[i] as f[i % pct(i)] + 1
        f[i] = f[j] + 1;
        assert(j < i);
    }
    string s;
    cin >> s;
    // reverse the binary string
    reverse(s.begin(), s.end());
    int tot = 0;
    // count the ones
    for (char ch : s){
        // add one to tot if ch is 1
        tot += (ch == '1');
    }

    vector<int> mods;
    // num isn't 0
    if (tot > 0) mods.pb(tot);
    // precompute the value of pc(x_i + 1)
    // it's either tot + 1 or tot -1 since we're
    //only inverting one bit
    if (tot > 1) mods.pb(tot -1);
    if (tot < n) mods.pb(tot + 1);
    vector<int> val(mods.size());

    // loop through possibilities for mod
    for (int i = 0; i < mods.size(); i++){
        int md = mods[i];
        // if md is 1 then the value is 0
        // otherwise it's md
        pw[i][0] = 1 % md;
        // loop through nums less than or equal to n
        for (int j = 1; j <= n; j++){
            // save the num as the previous num shifted left % mod
            pw[i][j] = (pw[i][j-1] << 1) % md;
        }
        for (int j = 0; j < n; j ++){
            // if there's a one
            if (s[j] == '1')
                // add the 
                val[i] = (val[i] + pw[i][j]) % md;
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++){
        // if it's a 1 we decrease our count
        // otherwise increase it because inverting 0 will make it 1
        int cur = tot + (s[i] == '0') - (s[i] == '1');
        if (cur == 0){
            ans.pb(0);
            continue;
        }
        int j = -1;
        // find a k such that the values line up
        for (int k = 0; k < mods.size(); k++){
            if (mods[k] == cur) j = k;
        }
        assert(j != -1);
        // index of correct val
        int curval = val[j];
        if (s[i] == '0') {
            // if it's zero increase it
            curval = (curval + pw[j][i]) % cur;
        }
        else {
            // decrease by pw[j][i]
            curval = (curval - pw[j][i] + cur) % cur;
        }
        // add the answer + 1
        ans.pb(1 + f[curval]);
    }
    reverse(ans.begin(), ans.end());
    for (int x : ans) cout << x << endl;
}

int main()
{
    //ifstream fin("frac1.in");
	//ofstream fout("frac1.out");
	io;
	solve();

	return 0;
}
