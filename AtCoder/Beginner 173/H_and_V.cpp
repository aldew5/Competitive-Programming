/*
ID: alec3
LANG: C++14
PROG:
*/
/*
We use bitmasks to test every possible combination of
rows and columns and for each we count the number of
black squares it leaves.  If that number is k we've
found a valid answer.
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

ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb)/2;
		f(mb)?rb=mb:lb=mb+1;
	}
	return lb;
}


int main()
{
    io;
    // store rows as binary strings in g
    string g[6];
    int h, w, k, ans = 0;
    cin >> h >> w >> k;

    // input
    FOR(i, 0, h){
        cin >> g[i];
    }

    // loop through 2 ^ h possibilities
    // 00000 -> 00001 -> 000010 -> 000011 -> 0000100 -> 0000101 -> ...
    // a 1 represents row we're coloring
    // we start with a single row and shift it 0 -> h pos with i2
    FOR (i, 0, 1 << h){
        // loop through 2 ^ w possibilities
        // same as above but a 1 represents a column we choose to color
        // start with a single column and shift it 0 -> w pos with j2
        FOR (j, 0, 1 << w){
            int c = 0;
            // loop through rows
            FOR (i2, 0, h){
                // loop through columns
                FOR (j2, 0, w){
                    // the & returns 1 only if the left operand has in one in the lowest
                    // order position (other positions are irrelevant)

                    // if there is a 0 in the i2th pos and a 0 in the j2th pos than we're keeping
                    // that square so check if it's black.  If it is count it
                    if ((i >> i2 & 1) == 0 && (j >> j2 & 1) == 0 && g[i2][j2] == '#'){
                        c ++;
                    }
                }
            }
            // correct number of black squares.
            if (c == k){
                ans ++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
