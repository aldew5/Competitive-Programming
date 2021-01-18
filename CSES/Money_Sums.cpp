/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Credit to icecuber
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
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}


using namespace std;

const ll MOD = 1e9 + 7;

bool dp[1001][100001];
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& it : a) cin >> it;

    dp[0][0] = true;

    vector<int> ans;
    // loop through the first i coins
    for (int i = 1; i <= n; i++){
        // for all the possible monetary values
        for (int j = 0; j <= 1000 * n; j++){
            dp[i][j] = dp[i-1][j];

            // we could make sum j with the first i-1 coins
            if (dp[i][j])
                continue;

            // because we are going to try every possible i
            // we are going to try every possible j with every possible
            // i
            // compute the remainder between the i-th coin and the desired
            // sum
            int r = j - a[i-1];

            // we can make the rth value with i-1 (or less) coins
            if (r >= 0 && dp[i-1][r])
                dp[i][j] = true;
        }

    }
    for (int j = 1; j <= 1000 * n; j++){
        if (dp[n][j])
            ans.pb(j);
    }

    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << " ";
    cout << endl;


    return 0;
}
