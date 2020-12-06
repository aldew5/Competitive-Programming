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


int main()
{
    // we always want to select the event that ends first
    int n, k; cin >> n >> k;
    vector<pair<ll, ll> > v;

    ll a, b;
    F0R(i, n){
        cin >> a >> b;
        v.pb({b, a});
    }
    sort(v.begin(), v.end());


    int ans = 0;
    multiset<int> st;

    for (int i = 0; i < n; i++){
        bool good = false;
        
        // there exists people to watch the movie
        if (!st.empty()){
            // find the person that is assigned to the clostest greater starttime
            auto it = st.upper_bound(v[i].ss);
            // it exists
            if (it != st.begin()){
                --it;
                // less than or equal to the start time
                // this person can watch the movie
                if (*it <= v[i].ss){
                    // person is no longer available
                    st.erase(it);
                    // they're booked until the end of this movie
                    st.insert(v[i].ff);
                    // we watched a movie
                    good = true; ans ++;
                }
            }
        }
        
        // we used only up to k people and didn't already update ans
        if (st.size() < k && !good){
            // update the multiset
            st.insert(v[i].ff);
            // increment
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
