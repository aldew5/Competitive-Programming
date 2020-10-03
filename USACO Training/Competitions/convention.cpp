/*
ID: alec3
LANG: C++14
PROG:
/*
Binary search on the answer. For each value of the wait-times check if it's possible
to have cows wait that long under the constraints of c and m.
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

int n, m, c;
ll ans = LLONG_MAX;

vector<ll> t;
bool okay(ll mins){
    ll buses = 0;
    for (int i = 0; i < t.size();){
        int j = i;
        for (; j < t.size(); j++){
            if (j - i + 1 > c)
                break;
            if (t[j] - t[i] > mins)
                break;
        }
        i = j;
        buses ++;
    }
    return (buses <= m);
}

int main()
{
    setIO("convention");
    cin >> n >> m >> c;
    ll it;
    FOR (i, 0, n){
        cin >> it;
        t.pb(it);
    }
    sort(all(t));



    ll low = 0, high = 1000000000;
    while (low <= high){
        int mid = (high + low) /2;
        if (okay(mid)){
            high = mid -1;
            ans = mid;
        }
        else
            low = mid + 1;

    }
    cout << ans << endl;



    return 0;
}
