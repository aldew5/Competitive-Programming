/*
Aldew
PROBLEM B: Honest Coach
*/
 
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <map>
 
using namespace std;
 

int main()
{
    int t;
    cin >> t;
 
    while (t--){
        int n;
        cin >> n;
        vector<int> s(n);
        for (auto& it : s) cin >> it;
 
        sort(s.begin(), s.end());
        int dif = 10001;
 
        for (int i = 0; i + 1 < s.size(); i++){
            if (abs(s[i] - s[i + 1])< dif) dif = abs(s[i] - s[i+ 1]);
        }
        cout << dif << endl;
    }
    return 0;
 
}
