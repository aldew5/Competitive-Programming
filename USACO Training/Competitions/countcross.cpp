/*
ID: alec3
LANG: C++14
PROG:
/*
Credit to Óscar Garries

Just do a flood fill from each cow (not crossing roads)
and check which of the cows haven't been reached.
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
#define mp make_pair

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

bool visit[100][100];
int cows[100][100], di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
int nCows, n, k, r;

set<tuple<int, int, int, int> > roads;

void flood(int i, int j, int i1, int j1) {
    if (i < 0 || j < 0 || i >= n || j >= n || visit[i][j] || roads.count(tie(i, j, i1, j1)))
        return;

    visit[i][j] = true;
    nCows += cows[i][j];

    // this is cool
    for (int k = 0; k < 4; k++){
        flood(i + di[k], j + dj[k], i, j);
    }
}


int main()
{
    setIO("countcross");

    cin >> n >> k >> r;

    for (int i = 0; i < r; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1--; y1--; x2--; y2--;
        tuple<int, int, int, int> cur = tie(y1, x1, y2, x2);
        tuple<int, int, int, int> cur1 = tie(y2, x2, y1, x1);
        roads.insert(cur);
        roads.insert(cur1);
    }

    for (int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        cows[y][x] ++;
    }

    vector<int> cowsComponent;
    int total = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (visit[i][j])
                continue;
            nCows = 0;
            flood(i, j, -1, -1);
            total += nCows;
            if (nCows)
                cowsComponent.pb(nCows);
        }
    }

    int ans = 0;
    for (int i = 0; i < (int) cowsComponent.size(); i++){
        for (int j = i + 1; j < (int) cowsComponent.size(); j++)
            ans += cowsComponent[i] * cowsComponent[j];
    }
    cout << ans << endl;

    return 0;
}
