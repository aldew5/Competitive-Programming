/*
Aldew
PROB: "Hungry Student Problem"
CLASSIFICATION: Greedy
DIFFICULTY: 900

Subtract the lowest value until you can no longer do so or
you reach a multiple of three or seven.
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--){
        int x;
        cin >> x;
        bool print = false;

        if (x < 3) cout << "NO" << endl;
        else if (x% 3 == 0 || x%7 == 0) cout << "YES" << endl;
        else {
            while (x - 3 >= 0) {
                x -= 3;

                if (x %7 == 0 || x % 3 == 0){
                    cout << "YES" << endl;
                    print = true;
                    break;
                }
            }
            if (!print) cout << "NO" << endl;
        }
    }
    return 0;
}

