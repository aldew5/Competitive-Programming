/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Realize that the optimal way to order the people is from 
greatest to least and at most we can add a val twice except
for the greatest val which we can only add once (because it 
represents the first person in the circle).
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
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& it : a) cin >> it;

    sort(a.rbegin(), a.rend());
    ll ans = a[0];
    int val = a[1];
    int pos = 1;
    FOR(i, 2, n){
        if (i + 1 == n)
            ans += val;
        else
            ans += 2 * val;
        i ++;
        pos ++;
        val = a[pos];
    }
    cout << ans << endl;
    return 0;
}
