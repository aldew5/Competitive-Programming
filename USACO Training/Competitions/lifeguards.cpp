/*
ID: alec3
LANG: C++14
PROG:
*/
/*
We want to fire the person that's working alone for the least
amount of time. Count this and subtract it from the total
time someone is working.
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

// custom Time struct to store information about the
// starting and ending times of the shifts
struct Time {
    int l, r;
};

// custom comparator (will sort shifts in increasing order)
bool cmp (const Time& a, const Time& b){
    return a.l < b.l;
}

int main() {
    setIO("lifeguards");

    int n;
    cin >> n;
    vector<Time> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i].l >> a[i].r;

    sort(a.begin(), a.end(), cmp);

    int ans = 0, val = 0, res = 0;

    // loop through the shifts
    for (int i = 0; i < n; i++){
        // the end of the current person's shift is after
        // the end of the next soonest shift
        if (a[i].r > res){
            // set val to the max of the result and the start
            // of the current shift
            val = max(res, a[i].l);
            // add the difference between the end of the shift
            // and the furthest left starting shift
            ans += a[i].r - val;
            // set res to the end of the current shift
            // (this will become the soonest starting shift for the next person)
            res = a[i].r;
        }
    }
    // out
    int out = ans;
    // set the end time to last
    Time last;
    last.l = a[n-1].r;
    a.pb(last);
    res = 0;
    // loop through the times
    for (int i = 0; i < n; i++){
        // the current value is the difference between the min value of the next person's
        // start time, the current person's end time and the max value of the
        // current person's start time and the max end time seen so far
        int cur = min(a[i +1].l, a[i].r) - max(a[i].l, res);
        // out becomes the current value if it's smaller than cur
        out = min(out, cur);
        // the result is the max end time
        res = max(res, a[i].r);
    }
    // make sure out isn't negative
    out = max(out, 0);
    // output the difference between ans and the min
    // gap time
    cout << ans - out << endl;



    return 0;
}
