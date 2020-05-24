/*
Aldew
PROBLEM D: Buying Shovels
*/
 
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <map>
 
using namespace std;
 
vector<int> solve(int n) {
    vector<int> ans;
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++){
        if (n%i == 0){
            // If divisors are equal, print only one
            if (n/i == i)
                ans.push_back(i);
 
            else // Otherwise print both
                ans.push_back(i);
                ans.push_back(n/i);
        }
    }
    return ans;
}
/*
 
*/
int main()
{
    int t;
    cin >> t;
 
    while (t--){
        int n, k;
        cin >> n >> k;
 
        if (k >= n) cout << 1 << endl;
        else {
            int res;
            vector<int> ans = solve(n);
            sort(ans.rbegin(), ans.rend());
 
            for (int i = 0; i < ans.size(); i++){
                if (ans[i] <= k){
                    res = ans[i];
                    break;
                }
            }
            cout << n/res << endl;
        }
    }
    return 0;
 
}
