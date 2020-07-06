/*
ID: alec3
LANG: C++14
PROG: milk
CLASSIFICATION: brute force
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    int n, m;
    fin >> n >> m;

    ll ans = 0;

    vector<pair<int, int>> a;
    int p, v;
    for (int i = 0; i < m; i ++){
        fin >> p >> v;
        a.push_back(make_pair(p, v));
    }
    sort(a.begin(), a.end());

    int c = 0;
    for (int i = 0; i < a.size(); i++){
        if (c + a[i].ss <= n){
            ans += a[i].ff * a[i].ss;
            c += a[i].ss;
        }
        else if (c + a[i].ss > a[i].ss){
            ans += a[i].ff * (n - c);
            break;
        }
    }
    cout << ans << endl;
    fout << ans << endl;


	return 0;
}
