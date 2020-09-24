/*
ID: alec3
LANG: C++14
PROG:
*/
/*
We maintain a set of all lengths and a set of all points. Every time
we read a new point, we find the range it impacts ([left, right]) and remove
the corrosponding length from the multiset. We can then replace it with the two
new created lengths.

We use a multiset because it allows us to store multiple lengths of the same
magnitude.
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

ifstream fin(".in");
ofstream fout(".out");

int n, m;


int main()
{
    io;
    cin >> n >> m;
    multiset<ll> t;
    ll a;
    FOR(i, 0, n){
        cin >> a;
        t.insert(a);
    }

    FOR(i, 0, m){
        cin >> a;
        if (t.empty() || a < *t.begin()){
            cout << -1 << endl;
            continue;
        }

        auto it = t.upper_bound(a);

        if (*it == a){
            cout << a << endl;
            t.erase(t.find(*it));
        }
        else {
            cout << *prev(it) << endl;
            t.erase(t.find(*prev(it)));
        }


    }

    return 0;
}
