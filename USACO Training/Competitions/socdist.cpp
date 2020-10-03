/*
ID: alec3
LANG: C++14
PROG: haircut
*/
/*
Brute force all the possible grids and test
each one.
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

int n, m;
ull a, b;

vector<pair<ull, ull> > grass;
bool okay(int D){
    int index = 0, val = 1;
    int pos = grass[0].ff;

    while (val < n && index < m){
        if (pos + D <= grass[index].ss){
            val ++;
            if (pos + D >= grass[index].ff){
                pos += D;
            }
            else {
                pos = grass[index].ff;

            }
            //cout << pos << endl;
        }

        else {
            index ++;
        }
    }
    //cout << "val " << val << endl;

    return val == n;

}

int main()
{
    setIO("socdist");
    cin >> n >> m;

    ull high = 0;
    FOR (i, 0, m){
        cin >> a >> b;
        grass.pb(mp(a, b));
        high = max(b, high);
    }
    sort(grass.begin(), grass.end());

    ull ans = 0;
    ull low = 1;
    high /= n;
    high ++;
   // cout << "HERE " << okay(2) << endl;

    while (low <= high){
        ull mid = (high + low) /2;
        //cout << "HIGH " << " " << high << " "<< low << " " << mid << endl;

        //cout << "HERE " << mid << "  " << okay(mid) << endl;
        if (okay(mid)){
            low = mid + 1;
            ans = max(ans, mid);
        }
        else
            high = mid - 1;
    }

    cout << ans << endl;

    return 0;
}
