/*
ID: alec3
LANG: C++14
PROG:
*/
/*
This a brute force problem.

Loop through all the possible quantities of swords p could take
and calculate how many of the other weapons p could take for each
choice. Calculate how many weapons f could take with the can_take
function, then output the greatest result.
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

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

//ifstream fin("maze1.in");
//ofstream fout("maze1.out");

ll can_take(ll s, ll w, ll cs, ll cw, ll p){
    if (s > w){
        // call the function again with the swapped values
        // so w >= s
        return can_take(w, s, cw, cs, p);
    }
    // we can't take all the swords (lightest weapon)
    // we take the max amount possible
    if (s * cs >= p)
        return p /s;
    // we can take all the swords
    // so we take them + max amount we can take
    // either the remaining space over the weight or all of them
    return cs + min((p - s * cs) /w, cw);
}
void solve(){
    ll p, f, cs, cw, s, w;
    cin >> p >> f >> cs >> cw >> s >> w;
    ll best = 0;

    // loop through number of swords to take
    for (ll i = 0; i <= cs; i++){
        // valid number of swords
        if (i * s <= p){
            // a is how many of the other swords we can take
            ll a = min((p - i * s) /w, cw);
            // the amount of weapons p can hold + the weapons that f can hold
            best = max(best, i + a + can_take(s, w, cs - i, cw - a, f));
        }
    }
    // output
    cout << best << endl;
    return;
}


int main()
{
    int t;
    cin >> t;
    while (t--){
        solve();
    }


    return 0;
}
