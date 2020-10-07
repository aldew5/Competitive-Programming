/*
ID: alec3
LANG: C++14
PROG:
/*
Pick the largest coordinate calculate the edge value
for tha coordinate and count up or down to the 
corrosponding x or y value.
*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" " << endl;
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
#define line cout << "--------------" << endl;

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
    //setIO("closing");
    int t;
    cin >> t;
    while (t--){
        ll x, y;
        cin >> x >> y;

        ll ans;
        if (x < y){
            if (y % 2 == 0)
                ans = ((y-1) * (y-1)) + x;
            else
                ans = (y * y) -x + 1;

        }
        else {
            if (x % 2 != 0)
                ans = ((x-1) * (x-1)) + y;
            else
                ans = x * x -y + 1;
        }
        cout << ans << endl;
    }

    return 0;
}
