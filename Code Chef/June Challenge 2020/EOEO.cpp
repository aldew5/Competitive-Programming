/*
Aldew
PROB: The Tom and Jerry Game!
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
#define ll long long int
#define ull unsigned long long


using namespace std;


int main()
{
    long long t;
    cin >> t;
    while (t--){
        ull ts, js;
        cin >> ts;

        ull tsc = ts;
        ull c = 0;
        ull p =0;

        while (ts % 2 == 0){
            p ++;
            ts /= 2;
        }
        js = pow(2, p+1);
        if (js <= tsc) c = tsc/js;
        cout << c << endl;


    }
    return 0;
}




