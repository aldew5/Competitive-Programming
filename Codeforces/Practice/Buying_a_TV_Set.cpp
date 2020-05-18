/*
Aldew
PROB: "Buying a TV Set"
CLASSIFICATION: math
DIFFICULTY: 1000
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <map>

using namespace std;
/*
Need to figure out how many numbers
can multiply x and y so that they're still
both less than the max values
*/

int main()
{
    long long max_w, max_h, x, y;
    cin >> max_w >> max_h >> x >> y;

    // x and y in lowest terms
    long long gcd = __gcd(x, y);
    x /= gcd;
    y /= gcd;

    if (x > max_w || y > max_h) cout << 0 << endl;
    else {

        // find max number x and y can be multiplied by
        // they can definitely be multiplied by lower numbers
        long long max_int = min(floor(max_w /x), floor(max_h / y));
        cout << max_int << endl;
    }

}
