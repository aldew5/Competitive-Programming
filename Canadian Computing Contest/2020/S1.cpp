/*
Aldew
PROB: Surmising a Sprinter's Speed
CLASSIFICATION: Implementation
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <map>
#include <math.h>
#include <cstdio>


using namespace std;


int main()
{
    int n;
    cin >> n;
    vector< pair<int, int> > s;

    int t, x;
    pair<int, int> p;
    while (n--){
        cin >> t >> x;
        p = {t, x};
        s.push_back(p);

    }
    sort(s.begin(), s.end());

    double speed = 0;
    double si;
    for (int i = 0; i < s.size(); i++){
        if (i + 1 < s.size()){
            si = abs(s[i].second - s[i+1].second);
            si /= abs(s[i].first - s[i+1].first);

            if (si > speed) speed = si;
        }
    }
    cout << speed << endl;
    return 0;
}
