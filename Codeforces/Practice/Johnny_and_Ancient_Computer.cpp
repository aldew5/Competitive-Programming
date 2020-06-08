/*
Aldew
PROB: Johnny and Ancient Computer
CLASSIFICATION: Implementation
DIFFICULTY: 1000
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


int twoCount(long long n){
    long long w = n;
    int c = 0;

    while (w % 2 == 0){
        w /= 2;
        c ++;
    }

    return c;
}

int main()
{
    int t;
    cin >> t;
    while (t--){
        long long a, b;
        cin >> a >> b;

        int ans = 0;
        double twos = 0;
        if (a > b){
            while(a % 2 == 0 && a > b){
                a /=2;
                twos ++;
            }
        }
        else{
            while(b % 2 == 0 && b > a){
                b /= 2;
                twos ++;
            }
        }
        ans += floor(twos/3);
        twos -= ans * 3;

        ans += floor(twos/2);

        twos -= floor(twos/2) * 2;
        ans += twos;


        if (a == b) cout << ans << endl;
        else cout << -1 << endl;

        }

    return 0;
}
