/*
Aldew
PROB: Nastya and Rice
CLASSIFICATION: math
DIFFICULTY: 900
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <map>

using namespace std;


int main()
{
    int t;
    cin >> t;

    while (t--){
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;

        int lower = (a - b) * n;
        int upper = (a + b) * n;

        if (upper < c-d || lower > c+d) cout << "No" << endl;
        else cout << "Yes" << endl;

    }

    return 0;

}
