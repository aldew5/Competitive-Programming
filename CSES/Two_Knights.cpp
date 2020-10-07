/*
ID: alec3
LANG: C++14
PROG:
/*

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


int main()
{
    //setIO("closing");
    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++){
        // possible moves for the first and second knight
        ll a = i * i;
        ll b = a * (a -1) /2;

        // if we have at least a 3x3 grid
        if (i > 2){
            // remove the places we can't place the knights
            // from the total possibilities
            b -= 4 * (i-1) * (i-2);
        }
        cout << b << endl;
    }


    return 0;
}
