/*
Aldew
PROB: Factorial
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
#define ll long long


using namespace std;
/*
Just count the multiples of 5^i up to n.
*/

int main()
{
    int T;
    cin >> T;
    while (T--){
        ll n;
        cin >> n;
        ll ans = 0;

        for (int i = 5; (n/i) > 0; i *= 5) ans += n/i;


        cout << ans << endl;
    }
    return 0;
}
