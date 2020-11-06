/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Since m is always in integer, we know that the sum must always be an integer.

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

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}


int main() {
    setIO("bcount");
    int n, q;
    cin >> n >> q;

    vector<int> a = {0}, b = {0}, c = {0};
    int s1 = 0, s2 = 0, s3 = 0, it;
    FOR(i, 0, n){
        cin >> it;
        if (it == 1)
            s1 ++;
        else if (it == 2)
            s2 ++;
        else
            s3 ++;
        a.pb(s1); b.pb(s2); c.pb(s3);
    }

    int x, y;
    FOR(i, 0, q){
        cin >> x >> y;
        cout << a[y] - a[x-1] << " " << b[y] - b[x-1] << " " << c[y] - c[x-1]<< endl;
    }



    return 0;
}
