/*
ID: alec3
LANG: C++14
PROG:
*/
/*
We need to take a prefix sum of all the three moves and check
at which point we have a maximum sum between the three.
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


using namespace std;

int main()
{
    setIO("hps");
    int n;
    cin >> n;

    vector<int> a = {0}, b = {0}, c = {0};
    int s1 = 0, s2 = 0, s3 = 0;
    char it;
    FOR(i, 0, n){
        cin >> it;
        if (it == 'H'){
            s1 ++;

        }
        else if (it == 'P'){
            s2 ++;

        }
        else {
            s3 ++;

        }
        a.pb(s1); b.pb(s2); c.pb(s3);
    }

    int ans = 0;

    for (int i = 1; i < a.size(); i++){
        int val = max({b[i-1], a[i-1], c[i-1]});
        int v2 = max({b[b.size() -1] - b[i-1], a[a.size()-1] - a[i-1], c[c.size()-1] - c[i-1]});

        ans = max(ans, val + v2);
    }
    cout << ans << endl;

    return 0;
}
