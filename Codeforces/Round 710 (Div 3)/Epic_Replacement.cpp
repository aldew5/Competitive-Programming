/*
ID: alec3
LANG: C++14
PROG:
*/
/*

*/


#include <bits/stdc++.h>

//#define check(x) cout<<(#x)<<": "<<x<<" " << endl;
#define line cout << "--------------------" << endl;
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

const ll INF = 1e10 + 70;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin); // see /general/io
		freopen((name+".out").c_str(), "w", stdout);
	}
}


int main()
{
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto& it : a) cin >> it;

        sort(a.begin(), a.end());

        priority_queue<ll> q;
        int prev = a[0], cnt = 1;
        for (int i = 1; i < n; i++){
            if (a[i] != prev){
                q.push(cnt);
                cnt = 1;
            }
            else
                cnt ++;
            prev = a[i];
        }
        q.push(cnt);


        while (q.size() > 1){
            ll a = q.top(); q.pop();
            ll b = q.top(); q.pop();
            //cout << "HERE " << a << " " << b << endl;
            a --; b --;
            if (a)
                q.push(a);
            if (b)
                q.push(b);
        }
        if (q.size() == 0)
            cout << 0 << endl;
        else
            cout << q.top() << endl;

    }

}
