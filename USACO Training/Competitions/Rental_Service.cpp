/*
ID: alec3
LANG: C++14
PROG: rental
*/
/*

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
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

ifstream fin("rental.in");
ofstream fout("rental.out");

int n, m, R;
vector<int> c, r;
ll cum[100001], ans, t;
vector<pair<int, int> > tmp;

int main()
{
    io;
    fin >> n >> m >> R;

    // read input and sort so that the most
    // valuable things come first
    c.resize(n);
    FOR(i, 0, n) fin >> c[i];
    sort(c.rbegin(), c.rend());

    FOR(i, 0, m){
        int q, p; fin >> q >>p;
        tmp.pb(mp(p, q));
    }
    sort(all(tmp));

    r.resize(R);
    FOR(i, 0, R) fin >> r[i];
    sort(r.rbegin(), r.rend());

    // create a prefix sum of the values of the rentals
    FOR(i, 0, r.size()) cum[i + 1] = cum[i] + r[i];
    // loop through the cows
    FOR(i, 0, n + 1){
        // the amount being paid for the i most fruitful cow's
        // milk + the rent we get for the rest of the cows
        ans = max(ans, t + cum[min(R, n -i)]);

        //  reached the end
        if (i == n)
            break;

        // current cow
        int cur = c[i];
        // there are still stores and our current value is positive
        while (tmp.size() && cur > 0){
            // z is the quantity that the store willing to take
            // the most will buy or the cur (in the case that the
            // store is willing to buy more milk than is available)
            ll z = min(tmp.back().ss, cur);
            // remove that milk from the store and from the cow
            tmp.back().ss -= z, cur -= z;
            // add the quantity of the milk * value
            // t will store the value of selling the i most
            // fruitful cow's milk
            t += z * tmp.back().ff;

            // if the store has reached capacity remove it
            if (tmp.back().ss == 0)
                tmp.pop_back();
        }
    }
    fout << ans << endl;

    return 0;
}
