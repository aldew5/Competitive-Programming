/*
ID: alec3
LANG: C++14
PROG: haircut
*/
/*
The optimal value is the median.
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


int n;
vector<ll> w;

int main()
{
    setIO("lemonade");
    cin >> n;
    ll it;
    FOR (i, 0, n){
        cin >> it;
        w.pb(it);
    }

    sort(w.rbegin(), w.rend());

    queue<ll> q;
    FOR (i, 0, n){
        if (q.size() <= w[i])
            q.push(w[i]);
        else
            break;
    }

    cout << q.size() << endl;
    return 0;
}
