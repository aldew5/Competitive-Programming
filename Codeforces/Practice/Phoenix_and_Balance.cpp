/*
Aldew
PROB: "Pheonix and Balance"
CLASSIFICATION: Greedy

2^n is alwasy greater than the sum of all the other
powers. Just add the smallest powers to the 2^n pile
and the greatest remaining to the other pile.
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
        int n;
        cin >> n;

        int a = pow(2, n);
        int b = 0;

        for (int i = 1; i < n/2; ++i){
            a += pow(2, i);
        }
        for (int i = n/2; i < n; ++i){
            b += pow(2, i);
        }
        cout << abs(a-b) << endl;

    }


    return 0;
}


