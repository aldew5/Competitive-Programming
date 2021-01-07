/*
ID: alec3
LANG: C++14
PROG:
*/
/*
We start from the leftmost cow. For each new cow, if we find it's first choice has been
picked already we switch out the cow who took it. We propagate this switch down the line of cows
until we have a valid solution.
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
#define F0R(i, a) for (int i = 0; i < (a); i++)

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
    int n;
    cin >> n;

    vector<ll> a(n);
    for(auto& it : a) cin >> it;

    set<ll> s;
    for (auto i : a)
        s.insert(i);

    cout << s.size() << endl;


    return 0;
}
