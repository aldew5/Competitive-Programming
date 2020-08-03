/*
ID: alec3
LANG: C++14
PROG: highcard
*/
/*
Find the longest possible length of the logs (max(logs))
and set the shortest p0ssible to 1.  Then just do binary
search to find the smallest possible answer that is correct
i.e. can be made with k cuts.
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


//ifstream fin("zerosum.in");
//ofstream fout("zerosum.out");
const int N=2e6+1;


int n, k;
ll a[N];
int main() {
    io;
    cin >> n >> k;
    ll l= 1, r;

    // read logs
    for (int i= 1; i <= n; i++){
        cin >> a[i];
        // set r to be the longest log
        r = max(r, a[i]);
    }

    //binary search
    // l is intially 1 (the smallest log size)
    // r is intially the greatest log length
    while (l != r){
        // (smallest log + biggest log) /2
        ll mid = (l + r) /2;
        // sum
        ll s = 0;

        // loop through logs
        for (int i =1; i <= n; i++){
            // add the (length of the log -1) / middle
            // - 1 is to round doen
            s += (a[i] -1) / mid;
        }
        // the sum is within the range of cuts
        // than set the right side to the middle value
        if (s <= k) r = mid;
        else {
            // too small (wasn't possible)
            l = mid + 1;
        }
    }
    // the smallest possible length
    cout << l << endl;
    return 0;
}
