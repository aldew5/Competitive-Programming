/*
Aldew
PROBLEM C: Similar Pairs
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
        vector<int> a(n);
        for(auto& it : a) cin >> it;
        sort(a.begin(), a.end());
 
        int odd = 0;
        int even = 0;
        int eo = 0;
 
        for (int i = 0; i < a.size(); i++){
            // pair an even with an odd
            if (i + 1 < a.size() && abs(a[i] - a[i+1]) == 1) {
                i ++;
                eo += 2;
            }
            else if (a[i] % 2 == 1){
                    odd++;
            }
            else if (a[i] % 2 == 0){
                even ++;
            }
        }
        if (odd % 2 == 0 && even % 2 == 0) cout << "YES" << endl;
        else {
            bool solved = false;
            while (eo > 0){
                odd --;
                even --;
                if (odd % 2 == 0 && even %2 == 0){
                    solved = true;
                    break;
                }
            }
            if (solved) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
 
}
