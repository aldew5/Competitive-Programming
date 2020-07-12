/*
Aldew
PROB: Global Warming
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
#include <stack>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main()
{
    io;

    while (true){
        int n;
        cin >> n;

        if (n == 0) break;

        vector<int> a(n);
        for(auto& it : a) cin >>it;

        vector<int> dif;
        for (int i = 0; i + 1 < n; i++){
            dif.push_back(a[i+1] - a[i]);

        }


        bool good = true;
        int ans = dif.size();

        for (int i = 1; i < dif.size(); i++){
            good = true;
            for(int j = 0; j < dif.size(); j++){
                if (i + j < dif.size() && dif[j] != dif[i+j]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
