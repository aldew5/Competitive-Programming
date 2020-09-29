/*
ID: alec3
LANG: C++14
PROG: moobuzz
*/
/*
credit to Benq
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

//ifstream fin("moobuzz.in");
//ofstream fout("moobuzz.out");

vector<int> save;

bool ok(int x) { return x % 3 && x % 5; }

int f(int N){
    int num = (N-1) /8;
    return save[N - 8 * num -1] + 15 * num;
}


int main()
{
    setIO("moobuzz");
    FOR (i, 1, 16) {
        if (ok(i))
            save.pb(i);
    }
    int n;
    cin >> n;
    cout << f(n) << endl;

}

