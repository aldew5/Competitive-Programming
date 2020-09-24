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

ll x, n;



int main()
{
    io;
    cin >> x >> n;

    vector<ll> p(n);
    for(auto& it : p) cin >> it;

    set<int> s = {0, x};
    multiset<int> multi = {x};
    FOR(i, 0, n){
        auto it = s.upper_bound(p[i]);
        int left = *prev(it), right = *it;

        // we only want to erase one instance of the length
        multi.erase(multi.find(right - left));
        multi.insert(p[i] - left); multi.insert(right - p[i]);

        s.insert(p[i]);

        // output the largest length
        cout << *multi.rbegin() << " ";

    }
    cout << endl;


    return 0;
}
