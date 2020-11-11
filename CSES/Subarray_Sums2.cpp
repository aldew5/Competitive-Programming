/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Keep an ongoing prefix sum and a map to count the number of times a sum has appeared.
At each point check if the prefix sum matches the sum we want or if there has existed 
a previous sum of numbers whose difference with the prefix sum is the required answer.
If this is the case add the number of times this occurred to the answer.
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
   // setIO("hps");
    ll n, x;
    cin >> n >> x;
    vector<int> a(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 0, pre = 0;
    map<ll, ll> m;
    for (int i = 0; i < n; i++){
        pre += a[i];
        if (pre == x)
            ans ++;
        if (m.count(pre - x)){
            ans += m[pre - x];
        }
        m[pre] ++;
    }
    cout << ans << endl;



    return 0;
}
