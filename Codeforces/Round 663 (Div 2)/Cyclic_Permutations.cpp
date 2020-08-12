/*
ID: alec3
LANG: C++14
PROG:
*/
/*
It can be proven that the answer is n! - 2 ^(n-1).
Just compute this result.
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
bool good;
const int MOD = 1e9 + 7;
int main()
{
    io;
    int n;
    cin >>n;
    ll ans = 1;
    ll fact = 1;
    for (int i = 1; i <= n; i++){
        if (i + 1 != n)
            ans *= 2;
        fact *= i;
        fact %= MOD;
        ans %= MOD;
    }
    fact -= ans;
    fact %= MOD;

    if (fact < 0)
        fact += MOD;
    cout << fact << endl;
    return 0;
}

