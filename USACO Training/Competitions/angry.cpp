/*
ID: alec3
LANG: C++14
PROG:
/*
We binary search on R. The max value is the largest value /2
and the smallest value is 1.

Sort the bales. The optimal positions for lauching each cow is with 
the end of its area of affect at the nearest un-blownup cow. Simulate
this for each R and return the smallest R
*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" " << endl;
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ld long double
#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define line cout << "--------------" << endl;

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}

ll n, k;
vector<ll> a;
bool okay(ll R){

    ll index = 0, c = 0;
    while (c <= k && index < n){
        ll val = a[index] + 2 * R;
        while (a[index] <= val && index < n)
            index ++;
        c ++;
    
    }

    return c <= k;
}

int main()
{
    setIO("angry");
    cin >> n >> k;
    ll it;
    FOR (i, 0, n){
        cin >> it;
        a.pb(it);
    }
    sort(all(a));

    ll ans = LLONG_MAX;
    ll low = 1, high = a[a.size() -1] /2;
    while (low <= high){
        ll mid = (high + low) /2;
        if (okay(mid)){
            ans = min(mid, ans);
            high = mid -1;
        }
        else
            low = mid + 1;
    }
    cout << ans << endl;

    return 0;
}
