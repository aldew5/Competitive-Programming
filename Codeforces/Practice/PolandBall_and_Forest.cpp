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
    int n, x, ans = 0;
    set<int> s;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x;
        // if tree only has one node just increment answer
        if (x == i)
            ans ++;
        // otherwise add it to the set
        else
            s.insert(x);
    }
    // single-node trees + number of unique nodes /2
    cout << ans + s.size() /2 << endl;


    return 0;
}
