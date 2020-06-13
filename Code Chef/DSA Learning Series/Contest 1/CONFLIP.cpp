/*
Aldew
PROB: Coin Flip
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
        ll g;
        cin >> g;
        while (g --){
            ll i, n, q;
            cin >> i >> n >> q;

            if (n % 2 == 0) cout << n/2 << endl;
            else {
                if (q == 1){
                    if (i == 2) cout << n/2 + 1 << endl;
                    else cout << n/2 << endl;
                }
                else if (q == 2){
                    if (i == 1) cout << n/2 + 1 << endl;
                    else cout << n/2 << endl;
                }
            }
        }
    }
    return 0;
}
