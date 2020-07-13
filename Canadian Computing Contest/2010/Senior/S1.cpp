/*
ID: alec3
LANG: C++14
PROG: Computer Purchase
CLASSIFICATION: Implementation
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ifstream fin (".in");
ofstream fout (".out");

int main() {
    io;

    int n;
    cin >> n;
    vector<pair<int, string>> vals;

    pair<int, string> p;
    for(int i = 0; i < n; i++){
        string name;
        cin >> name;
        int r, s, d;
        cin >> r >> s >> d;

        p = {2 * r + 3 * s + d, name};
        vals.push_back(p);

    }

    sort(vals.rbegin(), vals.rend());

    vector<string> a, b;
    if (n == 1) cout << vals[0].ss << endl;
    else if (n > 1){
        int val = vals[0].ff;
        int i = 0;
        while (vals[i].ff == val && i < vals.size()){
            a.push_back(vals[i].ss);
            i ++;
        }
        val = vals[i].ff;
        while (vals[i].ff == val && i < vals.size()){
            b.push_back(vals[i].ss);
            i++;
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a.size() >= 2){
            cout << a[0] << endl;
            cout << a[1] << endl;
        }
        else {
            cout << a[0] << endl;
            cout << b[0] << endl;
        }
    }
}
