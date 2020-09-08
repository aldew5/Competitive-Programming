/*
ID: alec3
LANG: C++14
PROG: ttwo
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

ifstream fin("0.in");
ofstream fout("ans.out");

// 10^3 * 100
int dp[100001];

int main()
{
    io;
    int n, W;
    cin >> n >> W;
    int w[n], v[n];

    for (int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
    }
    // set all numbers to greater than the
    // max weight (so they aren't valid solutiosn
    memset(dp, 0x3f, sizeof(dp));

    // you can make something with value 0
    dp[0] = 0;
    // loop through possible items
    for (int i = 0; i < n; i++){
        // loop through values
        for (int j = 100000 - v[i]; j >= 0; j--){
            // we can make the value j + v[i] with the min of
            // (the weight required for the j items + the weight of the new item),
            // and (the value of the ith item + the value of the jth item)
            // this is to check whether or not we've actually found a better solution,
            // one that uses the same weight to attain a greater value.
            dp[j + v[i]] = min(dp[j] + w[i], dp[j + v[i]]);
        }
    }
    // loop through values from top down and output the one
    // with the first valid weight.
    for (int i = 100000; i >= 0; i--){
        if (dp[i] <= W){
            cout << i << endl;
            break;
        }
    }


    return 0;
}
