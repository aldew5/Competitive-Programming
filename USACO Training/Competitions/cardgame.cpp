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
    setIO("cardgame");
    int n; cin >> n;
    vector<int> a, s;
    int x;
    F0R(i, n){
        cin >> x;
        a.pb(x); s.pb(x);
    }
    sort(s.begin(), s.end());

    int val = 1;
    set<int> b;
    F0R(i, s.size()){
        if (val < s[i]){
            b.insert(val);
            i--;
        }
        val ++;
    }


    int ans = 0;
   // cout << b.size() << endl;
    for (int i = 0; i < n; i++){
        auto it = b.upper_bound(a[i]);

        //cout << b.size() << " HERE" << endl;
        if (it != b.begin())
            ans ++;

        if (i != n-1){
            --it;
            b.erase(it);

        }

    }
    cout << ans << endl;


    return 1;
}
