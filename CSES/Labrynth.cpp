
/*
ID: alec3
LANG: C++14
PROG:
*/
/*

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
#define F0R(i, a) for (int i = 0; i < (a); i++)

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

const ll INF = 1e10 + 70;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;

void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}



char grid[1001][1001];
char pre[1001][1001];
bool visit[1001][1001];

int n, m;
string ans = "";

void bfs(pair<int, int> a, pair<int, int> b){
    queue<pair<int, int> > q;
    q.push(a);

    while (!q.empty()){
        pair<int, int> s = q.front();
        q.pop();

        if (visit[s.ff][s.ss])
            continue;

        visit[s.ff][s.ss] = true;

        if (s.ff == b.ff && s.ss == b.ss)
            return;


        if (s.ff + 1 < n && grid[s.ff + 1][s.ss] != '#' && !visit[s.ff + 1][s.ss]){
            pre[s.ff+1][s.ss] = 'U';
            q.push({s.ff + 1, s.ss});
        }
        if (s.ff -1 >= 0 && grid[s.ff -1][s.ss] != '#' && !visit[s.ff - 1][s.ss]){
            pre[s.ff-1][s.ss]= 'D';
            q.push({s.ff - 1, s.ss});
        }
        if (s.ss -1 >= 0 && grid[s.ff][s.ss-1] != '#' && !visit[s.ff][s.ss-1]){
            pre[s.ff][s.ss-1]= 'R';
            q.push({s.ff, s.ss-1});
        }
        if (s.ss +1 < m && grid[s.ff][s.ss+1] != '#' && !visit[s.ff][s.ss+1]){
            pre[s.ff][s.ss+1]= 'L';
            q.push({s.ff, s.ss+1});
        }


    }
}

int main()
{
    cin >> n >> m;

    char it;

    pair<int, int> start, dest;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];

            if (grid[i][j] == 'A')
                start = {i, j};

            if (grid[i][j] == 'B')
                dest = {i, j};

        }
    }

    bfs(start, dest);


    map<char, char> mp;
    mp['U'] = 'D';
    mp['D'] = 'U';
    mp['L'] = 'R';
    mp['R'] = 'L';

    if (!visit[dest.ff][dest.ss])
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        int a = dest.ff, b = dest.ss;
        string ans = "";
        while (a != start.ff || b != start.ss){
            ans += mp[pre[a][b]];
            //cout << pre[a][b] << " HERE" << endl;

            if (pre[a][b] == 'D')
                a ++;
            else if (pre[a][b] == 'U')
                a --;
            else if (pre[a][b] == 'L')
                b --;
            else if (pre[a][b] == 'R')
                b ++;

            //cout << a << " " << b << endl;
        }

        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        cout << ans << endl;
    }

}

