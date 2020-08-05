/*
ID: alec3
LANG: C++14
PROG:
*/
/*
This problem can be solved with brute force and greedy.
Just try every possible sum and for each sum loop through possible
smaller weights. If for a smaller weight there exists a valid
larger weight than update our answer with the minimum times we
have one of the weights. Realize that we will never overlap pairs
because we are trying different weights each time.

The special case is when the two weights are the same. In that
case we add half of the number of times the weight appears to our answer.
*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ld long double
#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int pct(int x) { return __builtin_popcount(x); }

int main()
{
    io;
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> cnt(n + 1);
        int it;
        // read input
        for (int i = 0; i < n; i++){
            cin >> it;
            // count how many times each value occurs
            cnt[it] ++;
        }

        int ans = 0, cur;
        // brute force all possible sums
        for (int s = 2; s <= 2 * n; s++){
            cur = 0;
            // loop through smallest weight in a team
            for (int i = 1; i < (s + 1) /2; i++){
                // no weight big enough (s -i is larger weight)
                if (s - i > n) continue;
                // we can obtain this min (cnt[i], cnt[s-i) times where
                // i and s-i are the two weights and cnt holds
                // how many times they occur
                cur += min(cnt[i], cnt[s-i]);
            }
            // if s is even then we could have a case
            // where i = (s + 1) /2 so we add the result when the weights are equal
            if (s %2 == 0) cur += cnt[s/2]/2;
            //update ans
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }


    return 0;
}
