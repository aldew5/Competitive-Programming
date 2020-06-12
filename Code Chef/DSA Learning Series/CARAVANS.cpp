/*
Aldew
PROB: Caravans
CLASSIFICATION: Implementation
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
#define ll long long


using namespace std;


int main()
{
    int T;
    cin >> T;
    while (T--){
        long long n;
        cin >> n;
        vector<long long> s;
        long long it;
        while (n --){
            cin >> it;
            s.push_back(it);
        }

        long long ans = 1;
        long long speed = s[0];
        for (long long i = 0; i < s.size(); i++){
            if (s[i] < speed) speed = s[i];

            if (i != 0 && s[i] <= speed) ans ++;

        }
        cout << ans << endl;
    }
}
