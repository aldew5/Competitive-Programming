/*
Aldew
PROB: Dreamoon and Ranking Collection
Classification: implementation
Difficulty: 900
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <string>

#define ll long long

using namespace std;


int main()
{
    int t;
    cin >> t;
    while (t--){
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (auto& it : a) cin >> it;

        int ans = 0;

        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++){
            if (a[i] == ans + 1) ans ++;
            else if (a[i] > ans + 1 && x == 0) break;
            else if (a[i] > ans + 1 && x != 0){
                ans ++;
                x --;
                i --;
            }
            else if (a[i] == ans){
                while (a[i] == ans){
                    i ++;
                }
                i --;
            }
        }

        ans += x;
        cout << ans << endl;
    }
    return 0;
}


