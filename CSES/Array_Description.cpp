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
// dp[i][x]
// the number of ways to fill the array up to i 
// if we use x for the ith value
int dp[100001][101];

int main()
{
    int n, m;
    cin >> n >> m;
    
    int x0;
    cin >> x0;
    // if the first number is a zero
    if (x0 == 0){
        // if we use 1 for the first value for 
        // every value in the array
        // we have one way of doing that for each index
        for (int i = 1; i<= 100; i++)
            dp[0][i] = 1;
    }
    // otherwise there is one additional option only for the first index
    else
        dp[0][x0] = 1;

    for (int i = 1; i < n; i++){
        int x;
        cin >> x;
        
        // if the next number is a 0
        if (x == 0){
            // for every possible j in the range of the max value
            for (int j = 1; j <= m; j++){
                // for each k in the set of possible surrounding values
                for (int k : {j-1, j, j+1}){
                    // if every k is possible
                    if (k >= 1 && k <= m){
                        // then this is a valid solution
                        // we can fill up to i using j for the ith value
                        // the number of times we can fill up to i-1 using k 
                        // for the i-1th value
                        dp[i][j] += dp[i-1][k];
                        // compute the answer MOD 
                        dp[i][j] %= MOD;
                    }

                }
            }
        }
        // non-zero
        else {
            // we must look at the possible values for surrounding numbers
            for (int k : {x-1, x, x+1}){
                // valid k
                if (k >= 1 && k <= m){
                    // we can fill up to the ith index with x 
                    // the number of times we can fill up to the i-1th index with a k
                    dp[i][x] += dp[i-1][k];
                    dp[i][x] %= MOD;
                }
            }
        }
    }
    int ans = 0;
    // for all the possible values
    for (int j =1; j <= m; j++){
        // sum up how many ways we can make the last value 
        // for each possible value
        // (zero-indexing)
        ans += dp[n-1][j];
        ans %= MOD;
    }
    // output
    cout << ans << endl;



    return 0;
}
