/*
ID: alec3
LANG: C++14
PROG:
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
 
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
 
int main()
{
    io;
    int n;
    cin >>n;
    vector<int> a(n);
    for(auto& it : a) cin >> it;
 
    vector<int> pre;
    pre.pb(0);
    int m = 0;
 
    for (int i = 0; i < a.size(); i++){
        m = max(m, a[i]);
        pre.pb(m);
    }
 
    ll ans = 0;
    for (int i=0; i < a.size(); i++){
        //cout << a[i] << " " << pre[i] << endl;
        if (a[i] < pre[i]){
            ans += (pre[i] - a[i]);
        }
    }
    cout << ans << endl;
 
    return 0;
 
}
