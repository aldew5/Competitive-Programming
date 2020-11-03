/*
ID: alec3
LANG: C++14
PROG:
/*
We can't iterate over all possibilities

We look at each pair of posts that have the same x or y coordinates (parallel).
We then go through all the other points and add |x-y|/2 * (y_p - y_x) or|x-y|/2 * (x_p - x_x) depening
on what axis the base is parallel to.
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

struct measurement {
  int day;
  int cow;
  int delta;
};


int main()
{
    setIO("measurement");
    int n, g;
    cin >> n >> g;

    vector<measurement> a(n);
    for (auto& it : a) {
    cin >> it.day >> it.cow >> it.delta;
    }
    // sort the days in increasing order
    sort(A.begin(), A.end(), [](const measurement& a, const measurement& b) {
    return a.day < b.day;
    });

    // sort the keys from hightest to lowest
    map<int, int, greater<int> > cnts;
    // we will only run out of gs after n + 1 moves (never)
    cnts[0] = n + 1;

    int result = 0;
    map<int, int> mp;
    // loop through the vector of measurement days
    for (auto& m : a) {
        // reference cow
        int& ref = mp[m.cow];
        // if this it the top that means this number had the greatest count (on board)
        bool wastop = ref == cnts.begin()->first;
        // we're changing the value of one of the numbers
        int wascnt = cnts[ref]--;
        // we no longer have any
        if (wascnt == 1) {
            cnts.erase(ref);
        }
        // update number
        ref += m.delta;
        // new value
        int iscnt = ++cnts[ref];
        // check if it's the most frequent
        bool istop = ref == cnts.begin()->first;
        if (wastop) {
            // change in top
            if (!istop || wascnt != 1 || iscnt != 1) {
                //update
                ++result;
            }
        }
        // new top
        else if (istop) {
            ++result;
        }
    }
    cout << result << endl;

    return 0;
}
