/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Just check every possible number between 0 and 2^9 -1 inclusive and
output the minimum one that works (passes check).
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


int n, m, p[210], d[210], ans;

// tests whether or not a number is a valid answer
// (for every i, is there a j that ands with it to make x)
bool Check(const int &x){
    // loop through p
	for(int i = 1; i <= n; ++i){
        // loop through d
		for(int j = 1; j <= m; ++j){
            // there exists and i and j such that
            // i & j results in the answer
            if(((p[i] & d[j]) | x) == x){
                // stay in the function and check the rest
                // of the numbers in p
                goto Next;
            }
		}
		return 0;
		Next:;
	}
	// possible
	return 1;
}

int main()
{
    io;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)

        cin >> p[i];
    for (int i = 1; i <= m; i++)
        cin >> d[i];

    // max possible value (worst case)
    ans = (1 << 9) -1;

    // loop through possibilities
    for (int i = 8; i >= 0; i--){
        // if it was valid XOR ans with the 1 shifted i bits
        // otherwise do nothing
        // the XOR only keeps digits that are required by every solution

        Check(ans^(1 << i)) ? ans ^= (1 << i) : 0;

    }
    cout << ans << endl;


    return 0;

}
