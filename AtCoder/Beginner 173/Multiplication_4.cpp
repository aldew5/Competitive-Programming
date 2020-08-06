/*
ID: alec3
LANG: C++14
PROG:
*/
/*
First determine weather it's possible to have a positive answer.
If it isn't then we need to make it the least negative possible by sorting
the array from smallest to largest.

Otherwise take the products of numbers from the positive and negative arrays
(that are sorted) and use the largest k/2 products to create the answer.
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
bool absComp (int i, int j) { return (abs(i) < abs(j)); }


const ll MOD = 1e9+7;
void add(ll &a, ll b){
    a = (a+b) % MOD;
}
void mul(ll &a, ll b){
    a = a*b % MOD;
}
int main()
{
    io;
    int n, k;
    cin >> n >> k;

    vector<ll> a, apos, aneg;
    // store values in three vectors
    // a holds the abs, aneg holds negative nunmbers
    // apos holds positive values
    for(int i = 0; i < n; i++){
        int it;
        cin >> it;
        a.push_back(abs(it));

        if(it > 0)
            apos.push_back(it);
        if(it < 0)
            aneg.push_back(abs(it));
    }
    // store sizes
    int szp = apos.size(), szn = aneg.size();

    ll ans = 1;
    // if the number of positive values + the floor of
    // num negative /2 greater than k and (k is even or there are more than 0 positives)
    // determine if we can create a positive answer
    if(szp + szn/2*2 >= k && (k%2 == 0 || szp > 0)){
        // sort from greatest to least
        sort(apos.rbegin(), apos.rend());
        sort(aneg.rbegin(), aneg.rend());

        // if k is odd set ans to the first value in apos
        if(k%2)
            ans = apos[0];

        vector<ll> v;
        // if k was odd skip the first number
        for(int i = k % 2; i + 1 < szp; i += 2){
            // store the products of adjacent postitive numbers
            v.push_back(apos[i]*apos[i+1]);
        }
        for(int i = 0; i+1 <szn; i += 2) {
            // store the products of adjacent negative numbers
            // these are sorted from biggest to smallest
            v.push_back(aneg[i]*aneg[i+1]);
        }
        // sort the products from biggest to smallest
        sort(v.rbegin(), v.rend());
        // take the first k/2 products and compute them MOD
        // with mul
        for(int i = 0; i < k /2; i++)
            mul(ans, v[i] % MOD);

    }
    // answer will be negative
    else {
        // make it the least negative
        sort(a.begin(), a.end());
        FOR (i, 0, k)
            mul(ans, a[i]);
        ans = (MOD - ans) % MOD;
    }
    cout << ans << endl;

    return 0;
}
