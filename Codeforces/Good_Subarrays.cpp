/*
ID: alec3
LANG: C++14
PROG:
*/
/*
By definition for a subarray to be good the following must be true:
p_r - p_l = r -1 (the sum == the range) so p_r - r = p_l - l.  Therefore
we just need to count the p_i -is and the answer will be their count /2.  

This is because if we p_i1 - i1 = p_i2 - i2 we know that there is a good
subarray from i1 to i2.
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


int main()
{
    io;
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string a;
        cin >> a;

        map<int, int> m;
        // we can always make 0
        m[0] = 1;

        ll ans = 0, s = 0;
        // loop through a
        for (int i = 0; i < n; i++){
            // update the prefix sum
            s += a[i] - '0';
            // s - (i + 1) is the sum - the length of the sum 
            // we want this to be zero
            int x = (s - (i + 1));
            // increment ans by the number of times we've 
            // had x before
            ans += m[x];
            // update m[x]
            m[x] ++;
        }
        cout << ans << endl;
    }

    return 0;

}
