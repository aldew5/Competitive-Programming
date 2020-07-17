/*
Aldew
LANG: C++14
PROG: Camel Train
CLASSIFICATION: greedy
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

/*
Start with ans as the smallest possible value and then
every time you find a more optimal pairing in solve, add the
improvement to ans.

In solve, we're keeping a set (ordered) of positions and removing
positions when they are taken by the current most valuable camel.

*/

/*
Finds the optimal ordering of the elements in
the vector so that their value is maximized
*/
// piar: {difference, pos}
ll solve(vector<pair<ll, int>> & in){
    int n = in.size();
    // sort and reverse the input vector
    sort(in.rbegin(), in.rend());

    // create a set to contain camels
    set<int> is;
    // insert all the positions from 1 to n (the length of the input)
    for (int i = 1; i <= n; i++){
        is.insert(i);
    }

    ll ans = 0;
    // loop through the values in in (biggest values first)
    for (auto it : in){
        // set itr to the first number greater than k for
        // each camel in is
        auto itr = is.upper_bound(it.ss);
        // if the first element in the set is greater
        // then the position's already been filled and we can't
        // use the optimal value for that camel
        if (itr == is.begin()) continue;
        // else erase it from the set
        is.erase(prev(itr));
        // and add it to ans
        ans += it.ff;

    }
    return ans;

}

int main()
{
	int t;
	cin >> t;
	while (t--){
        int n;
        cin >> n;
        ll ans = 0;

        vector<pair<ll, int>> lc;
        vector<pair<ll, int>> rc;

        for (int i = 0; i < n; i++){
            int k;
            ll l, r;
            cin >> k >> l >> r;

            // more valuable to be on left side
            if (l > r){
                // increment ans by the lowest value it could take on
                ans += r;
                // save it to the left values vector
                lc.push_back({l-r, k});
            }
            else {
                ans += l;
                rc.push_back({r-l, n-k});
            }
        }
        // the lowest possible value + the optimal gain on left side +
        // gain on right side
        cout << ans + solve(lc) + solve(rc) << endl;
	}
	return 0;
}
