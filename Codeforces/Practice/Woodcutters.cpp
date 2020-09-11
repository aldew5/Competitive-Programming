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
#define FOR(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

ifstream fin("0.in");
ofstream fout("ans.out");

int l[100001];
int r[100001];
int stand[100001];

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> trees = {{0, 0}};

    memset(l, 63, sizeof(l));
    memset(r, 63, sizeof(r));
    memset(stand, 63, sizeof(stand));

    ll a, b;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        trees.pb(make_pair(a, b));
    }
    sort(trees.begin(), trees.end());
    r[0] = 0; l[0] = 0; stand[0] = 0;

    for (int i = 1; i <= n; i++){
        stand[i] = min({stand[i-1] +1, r[i-1] + 1, l[i-1] + 1});

        // check if we can fell left
        ll dif = trees[i].ff - trees[i].ss;
        if (i == 1 || dif > trees[i-1].ff){
            //cout << "HERE" << i << endl;
            l[i] = min(l[i-1], stand[i-1]);

            // we can fell left even if well fell right last time
            if (dif > trees[i-1].ff + trees[i-1].ss){
                l[i] = min(l[i], r[i-1]);
            }
        }
        // we can go right
        if (i + 1 > n || trees[i].ff + trees[i].ss < trees[i + 1].ff){
            r[i] = min({l[i-1], stand[i-1], r[i-1]});
        }

    }

    cout << n - min({stand[n], r[n], l[n]}) << endl;



    return 0;
}
