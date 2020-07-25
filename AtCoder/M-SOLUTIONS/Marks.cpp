/*
ID: Aldew
LANG: C++14
PROG:
*/
/*
Realize that you only have to look at the i-kth element
of a and the ith element of k to see which product will 
be bigger.
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

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (auto& it : a) cin >> it;

    for (int i = k; i< n; i++){
        if (a[i] > a[i -k]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    // on each day you either sell all or buy all or do nothings


    return 0;
}
