/*
ID: Aldew
LANG: C++14
PROG:
*/
/*
Realize that you will gain money as long as the 
next day's stock price is greater than today's. If 
that is the case buy as many stocks as you can afford 
and sell them at the increased rate.
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

//ifstream fin("lamps.in");
//ofstream fout("lamps.out");
const int sz = 85;
int a[sz];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll now = 1000;
    
    // loop through vals
    for (int i = 0; i + 1 < n; i++){
        // if there's a bigger stock price coming up
        if (a[i] < a[i+1]){
            // buy c stocks
            ll c = now / a[i];
            // and gain the difference in price 
            // times the number of stocks (sell them the next day)
            now += c * (a[i+1] - a[i]);
        }
    }
    cout << now << endl;


    return 0;
}
