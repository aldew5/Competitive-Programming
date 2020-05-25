/*
Aldew
PROB: Simple Polygon Embedding
CLASSIFICATION: math. geometry, binary search,
                ternary search
DIFFICULTY: 1400
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <map>
#include <math.h>

using namespace std;


int main()
{
    int t;
    cin >> t;
    double pi = 2*acos(0.0);

    while (t--){
        double n;
        cin >> n;
        double ans = 1/tan(pi/(2*n));

        cout << setprecision(9) << std::fixed << ans  << endl;

    }

    return 0;

}

