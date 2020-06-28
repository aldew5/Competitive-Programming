/*
Aldew
PROB: Distinct Pairs
CLASSIFICATION:
DIFFICULTY:
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() 
{
    io;
    
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> a(n);
    vector<pair<int,int>> b(m);

    //keep track of indices using pair
    // to represent value and pos
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    for (int i = 0; i < m; i++) {
        // pair the min value in a with all the values in b
        // this results in m distinct pairs
        cout << a[0].second <<" "<< b[i].second << endl;

    }
    for (int i = 1; i < n; i++) {
        // pair all the vlaues in a with the largest value in b except the first
        // this results in n -1 different pairs
        cout << a[i].second << " " << b[m-1].second << endl;
    }
 	return 0;
}
