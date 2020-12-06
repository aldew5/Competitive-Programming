/*
ID: alec3
LANG: C++14
PROG:
/*

*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" " << endl;
#define line cout << "--------------" << endl;
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ld long double

#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, n) for (int i = 0; i < n; i++)


typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}


int main()
{
    int n;
    cin >> n;
    map<int, int> mp;

    int k = 0;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        auto it = mp.upper_bound(a);

        // a is bigger than anything in mp
        // need a new stack
        if (it == mp.end())
            k ++;
        // the stored value assosciated with the first greater
        // element is 0
        else if (--it -> second == 0)
            mp.erase(it);
        // we know have a stack with a as the top element
        mp[a] ++;
    }
    cout << k << endl;

    return 0;
}
