/*
Aldew
PROB: Sum of Odd Integers
Classification: math
Difficulty: 1100
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <string>

#define ll long long

using namespace std;

/*
Sum of the first k elements is k^2. If that's greater than
n it's not possible.

If it's less than n the difference must be divisible by two
because you must be able to add some multiple of two to the greatest
element to increase the sum.
*/

int main()
{
    int t;
    cin >> t;

    while (t--){
        ll n, k;
        cin >> n >> k;

        ll val = k * k;
        if (val > n) cout << "NO" << endl;
        else {
            if ((n - val) % 2 == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;

}
