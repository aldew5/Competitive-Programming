/*
ID: alec3
LANG: C++14
PROG:
*/
/*
If we have two prefix sums with the same value mod n and we take
their difference we will end up with a number divisible by n. Therefore
the answer is the sum of the number of prefix sums divisible by n and the
number of pairs of values for each number [1, n-1].

We only want to look at surplus so we compute positive mods. We could alternately look
only at deficits for the same result.
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

int main()
{
    // setIO("hps");
    ll n;
    cin >> n;

    vector<ll> a(n);
    FOR (i, 0, n){
        cin >> a[i];
    }

    ll pre = 0, ans = 0;
    map<ll, ll> mp;
    // sum of all the things before the first element is zero (none)
    mp[0] ++;

    FOR (i, 0, n){
        // compute positive mods
        pre = (pre + a[i] % n + n) % n;
        // all the previous subarrays with the same surplus
        ans += mp[pre];
        // add the new prefix sum
        mp[pre] ++;

    }



    cout << ans << endl;



    return 0;
}
