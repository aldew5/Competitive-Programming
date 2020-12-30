/*
ID: alec3
LANG: C++14
PROG:
/*
If there is a pal larger than 3 then there is also
a pal of length 2 and a pal of length 3.

Locate either one of these in O(N) and mark any of the chars
in it as needing to be switched.

We will pick up all the chars this way even if it's not in the same
iteration of the loop.

Many people used dp. What a fucking problem
*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" " << endl;
#define line cout << "--------------" << endl;
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ld long double

#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, n) for (int i = 0; i < n; i++)


typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

bool used[100001];

int main ()
{
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        // update used
        FOR(i, 0, int(s.size()) + 1){
            used[i] = false;
        }

        int ans = 0;
        // loop through the string starting at the third index
        for (int i = 1; i < s.size(); i++){

            bool need = false;

            // if the current char is the same as the previous
            // and we haven't used the previous (length two pal)
            if (s[i] == s[i-1] && !used[i-1])
                need = true;
            // length 3 pal
            if (i >= 2 && s[i] == s[i-2] && !used[i-2]){
                need = true;
            }
            // mark the ith character as needing to be switched
            used[i] = need;
            // update ans
            ans += used[i];
        }
        cout << ans << endl;
    }

    return 0;
}
