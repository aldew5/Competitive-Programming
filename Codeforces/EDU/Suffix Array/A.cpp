/*
ID: alec3
LANG: C++14
PROG: suffix array
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



int main()
{
    string s;
    cin >> s;
    s += "$";

    int n = s.size();
    vector<int> p(n), c(n);

    {
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++) a[i] = {s[i], i};
        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++){
            if (a[i].first == a[i-1].first){
                c[p[i]] = c[p[i-1]];
            }
            else {
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
    }


    int k = 0;
    while ((1 << k) < n){
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; i++){
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++){
            if (a[i].first == a[i-1].first){
                c[p[i]] = c[p[i-1]];
            }
            else {
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
        k ++;
    }
    for (int i = 0; i < n; i++){
        cout << p[i] << " ";
    }
    cout << endl;


    return 0;
}
