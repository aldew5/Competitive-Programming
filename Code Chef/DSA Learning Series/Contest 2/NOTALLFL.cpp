/*
Aldew
PROB: Multiple of Three
CLASSIFICATION: Math
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
#define int long long


typedef long long ll;

using namespace std;


int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while (t--){
        int n, k;
        cin>> n >> k;
        int arr[n];
        for(int i = 0; i < n; i++) cin>>arr[i];

        int dflav = 1;
        int l = 0, r = 0;
        
        int flavf[k+1];
        for(int i = 0;i<=k;i++) flavf[i] = 0;

        flavf[arr[0]] = 1;
        int maxrange = 1;
        while(true){
            
            // not going over n and dflav is still valid
            while(++r < n && dflav < k){
                // first occurence
                if(flavf[arr[r]] == 0) dflav++;
                flavf[arr[r]] ++;
                
                // update maxrange if a new max range has been found
                if(dflav < k) maxrange = max(maxrange, r-l+1);

            }
            // we've gone through every index of r
            if(r == n) break;
            
            // dflav became too great
            r--;
            // move up l until we have a valid sequence
            while(l <= r && dflav == k){
                if(flavf[arr[l]] == 1) dflav --;
                flavf[arr[l]]--;
                l++;
            }
            // then go back to incrementing r
        }
        cout<< maxrange <<endl;
    }
    return 0;
}
