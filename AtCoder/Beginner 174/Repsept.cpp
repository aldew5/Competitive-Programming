/*
ID: Aldew
LANG: C++14
PROG: repsept
(credit tmwilliamlin)
*/


#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define FOR(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

//ifstream fin("zerosum.in");
//ofstream fout("zerosum.out");

void solve(){
    ll k;
    cin >> k;
    if (k % 7 == 0){
        // if k has a factor of 7 divide it out
        k /= 7;
    }
    // even numbers or numbers with a factor of 5 are impossible
    if(k % 2 == 0 || k % 5 == 0){
        cout << -1 << endl;
        return;
    }
    //otherwsie it's possible

    k *= 9;
    int ans = 1;

    // if k > 10 p = k
    ll p = 10 % k;

    // while the remainder of p * 10 % k
    // isn't one
    while (p != 1){
        // p is p x 10 mod k
        p = p * 10 % k;
        ans ++;
    }
    cout << ans << endl;
    return;
}

int main() {
    io;
    solve();

    return 0;
}
