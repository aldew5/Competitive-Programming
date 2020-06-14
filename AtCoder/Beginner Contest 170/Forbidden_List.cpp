/*
Aldew
PROB: Forbidden List
CLASSIFICATION: Math, sorting
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
#define ll long long int
 
 
using namespace std;
 
 
int main()
{
    int x, n;
    cin >> x >> n;
 
    int ans;
    if (n == 0){
        ans = x;
    }
    else {
        vector<int> a(n);
        for (auto& it : a) cin >> it;
 
        sort(a.begin(), a.end());
 
        map<int, int> d;
        vector<int> in;
 
        bool isIn;
 
        for (int i = 0; i < a.size(); i++){
            d[abs(x - a[i])] ++;
 
 
            isIn = false;
            for (int j = 0; j < in.size(); j++){
                if (in[j] == (abs(x-a[i]))){
                    isIn = true;
                    break;
                }
            }
            if (!isIn) in.push_back(abs(x-a[i]));
        }
 
        sort(in.begin(), in.end());
 
        ans = x - (in[in.size() -1] + 1);
        bool good = true;
        for (int i = 0; i< a.size(); i++){
            if (a[i] == ans){
                good = false;
                break;
            }
        }
        if (!good) ans = x + in[in.size() -1] + 1;
 
 
        if (in[0] > 0) ans = x;
        else{
            for (int i = 0; i < in.size(); i++){
                if (i -1 >= 0 && in[i-1] + 1 != in[i]) {
                    ans = x - (in[i-1] + 1);
                    break;
                }
                else if (d[in[i]] < 2 && in[i] != 0){
                    int p1 = x + in[i];
                    int p2 = x - in[i];
 
                    ans = p2;
                    for (int i = 0; i < a.size(); i++){
                        if (a[i] == p1){
                            ans = p2;
                            break;
                        }
                        else if (a[i] == p2){
                            ans = p1;
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}
