/*
Aldew
PROB: Wormholes
CLASSIFICATION: Iterators
DIFFICULTY:
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <map>
#include <math.h>
#include <cstdio>
#include <stack>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main()
{
    fio;

    ll n, x, y;
    cin >> n >> x >> y;

    vector<pair<int, int>> contests;
    pair<int, int> t;
    int s, e;
    for (int i = 0; i < n; i++){
        cin >> s >> e;
        t = {s, e};
        contests.push_back(t);
    }
    vector<int> v(x);
    for (auto& it : v) cin >> it;

    vector<int> w(y);
    for(auto& it : w) cin >> it;


    sort(v.begin(), v.end());
    sort(w.begin(), w.end());

    ll ans = LLONG_MAX;

    for (int i = 0; i < contests.size(); i++){
        // returns an iterator that points to the first element greater than
        // contest[i].first
        auto lower = lower_bound(v.begin(), v.end(), contests[i].first);
        // and one that's less than contest[i].second
        auto upper = upper_bound(w.begin(), w.end(), contests[i].second);

        // since lower is not less than val we need to subtract one unless its
        // equal to val
        if (*lower != contests[i].first) lower -= 1;
        // since upper is inherantly greater than val, upper -l could be equal to val
        if (*(upper - 1) == contests[i].second) upper -= 1;

        // ensure that there existed an answer
        if (*lower <= contests[i].first && *upper >= contests[i].second){
            ans = min((ll)(*upper - *lower+1), ans);
        }

    }
    cout << ans << endl;


    return 0;
}





