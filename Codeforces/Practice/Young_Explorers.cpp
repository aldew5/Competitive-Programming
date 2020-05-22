/*
Aldew
PROB: "Young Explorers"
CLASSIFICATION: Dp, Greedy, Sortings
DIFFICULTY: 1200
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
        vector<int> e(n);
        for (auto& it : e) cin >> it;
        sort(e.begin(), e.end());


        int ans = 0, c = 0;
        for (int i = 0; i < e.size(); i++){
            // check if the last element in the group is valid
            if (++c == e[i]){
                ans ++;
                c = 0;
            }
        }
        cout << ans << endl;
        }
    return 0;

}

