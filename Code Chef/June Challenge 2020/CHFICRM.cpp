/*
Aldew
PROB: Chef and Icecream
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

using namespace std;


int main()
{
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& it : a) cin >> it;

        bool good = true;

        map<int, int> cash;
        for (int i = 0; i < n; i++){
            if (a[i] == 15){
                if (cash[10] >=1) cash[10] -= 1;
                else if (cash[5] >= 2) cash[5] -= 2;
                else {
                    good = false;
                    break;
                }
            }
            else if (a[i] == 10){
                if (cash[5] >= 1) {
                    cash[5] --;
                    cash[10] ++;
                }
                else {
                    good = false;
                    break;
                }

            }
            else if (a[i] == 5) cash[5] ++;
        }

        if (good) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}
