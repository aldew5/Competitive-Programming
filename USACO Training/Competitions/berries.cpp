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
int n, k;
vector<int> a;


int main ()
{
    setIO("2");
    cin >> n >> k;

    int it, mx = 0;
    F0R(i, n){
        cin >> it;
        a.pb(it);
        mx = max(mx, it);
    }

    int cnt, val;
    int ans = 0;
   // sort(a.rbegin(), a.rend());
    for (int i = 1; i <= mx; i++){
        cnt = 0, val = 0;
        int index = 0;
        while (cnt <= k/2 && index < n){
            cnt += a[index] / i;
            index ++;
        }
        if (cnt > k/2){
            val += cnt - k/2;
        }
        else if (cnt < k/2 || index == n)
            continue;
        for (int j = index; j < n; j++)
            val += a[j]/ i;

        if (val >= k/2)
            ans = max(k/2 * i, ans);
    }
    cout << ans << endl;



    return 0;

}

