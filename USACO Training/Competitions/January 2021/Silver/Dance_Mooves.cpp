
/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Credit to Chris Zhang
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

const ll MOD = 1e9 + 7;
const ll INF = 1e10 + 70;
const ll MX = 2 * 1e6;

int n, k;
// input
int A[200001],B[200001];
int P[100001];
vector<int>S[100001];
//from[i] = where the cow in position i originated from
int from[100001];
//array to keep track of uniquePos
int cnt[100001];
//# of unique reachable positions
int uniquePos;


// add in S_node
void add (int node){
    for (int x : S[node]){
        if (cnt[x] == 0)
            uniquePos ++;
        cnt[x] ++;
    }
}

// remove S_node
void rem(int node){
    for (int x : S[node]){
        if (cnt[x] == 1)
            uniquePos --;
        cnt[x] --;
    }
}

bool vis[100001];
// nodes in current cycle
queue<int> q;

void dfs(int node){
    vis[node] = true;
    add(node);

    q.push(node);
    if (!vis[P[node]])
        dfs(P[node]);
}


int main()
{
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> A[i] >> B[i];
    for (int i = 1; i <= n; i++){
        from[i] = i;
        S[i].pb(i);
    }

    // simulate the first k steps
    for (int i = 0; i < k; i++){
        S[from[A[i]]].pb(B[i]);
        S[from[B[i]]].pb(A[i]);
        swap(from[A[i]], from[B[i]]);
    }

    for (int i = 1; i <= n; i++){
        P[from[i]] = i;
    }

    int ans[100001];
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            dfs(i);
            int tempAns = uniquePos;

            // assign the ans to all nodes in the cycle, which
            // are stored in the queue
            while (!q.empty()){
                rem(q.front());
                ans[q.front()] = tempAns;
                q.pop();
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}

