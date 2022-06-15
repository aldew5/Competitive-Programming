/*
ID: alec3
LANG: C++14
PROG:
/*
Just add the greatest weight (to the oringal count) the number of 
times there are edges out of it. Essentially we double it up optimally
(when we count it for each edge)

Credit to tourist for the clever solution 
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

bool used[100001];

int main ()
{
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> w(n);

        ll total = 0;
        // read in weights and take their sum
        F0R(i, n){
            cin >> w[i];
            total += w[i];
        }
        // store the degree of each node (zero indexed)
        vector<int> deg(n);
        F0R(i, n-1){
            int x, y;
            cin >> x >> y;
            x--; y--;
            deg[x] ++; deg[y] ++;
        }
        vector<int> path;
        // loop through the nodes
        F0R(i, n){
            // for each edge leaving the node minus the one coming
            // from it (avoid double counting)
            // add the weight to the path the number of times it occurs
            for (int j = 0; j < deg[i] -1; j++){
                path.pb(w[i]);
            }
        }
        // sort in reverse order
        sort(path.rbegin(), path.rend());
        cout << total << " ";
        
        // the optimal solution is adding the greatest
        // weights first by the degree of the node
        for (int i : path){
            total += i;
            cout << total << " ";
        }
        cout << endl;
    }

    return 0;
}
