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
#define ld long double
#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

using namespace std;

pair<int, int> w[1024];

int main()
{
    int n, m, k, t;
    cin >> n >> m >> k >> t;

    pair<int, int> x;

    int a, b;
    for (int i = 1; i <= k; i++){
        cin >> a >> b;
        w[i] = make_pair(a, b);
    }
    // sort the coordinates
    sort(w + 1, w + k + 1);


    for (int i = 1; i <= t; i++){
        cin >> a >> b;
        x = make_pair(a, b);
        // check for the coordinate in the list of waste coordinates
        int j = lower_bound(w + 1, w + k + 1, x) -w;

        // we found it
        if (w[j] == x)
            cout << "Waste" << endl;
        else {
            j --;
            // the number of full rows * boxes per row + cells on
            // last row - how many waste boxes there are up to this point
            int all = (a-1) * m + b - j;
            all %= 3;

            // output answer
            if (all == 1)
                cout << "Carrots" << endl;
            else if (all == 2)
                cout << "Kiwis" << endl;
            else
                cout << "Grapes" << endl;
        }
    }
    return 0;
}
