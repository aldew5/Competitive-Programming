/*
Aldew
PROB: New Theatre Square
Classification: dp, greedy, implementation, two pointers
Difficulty:
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;


int main()
{
    int t;
    cin >> t;

    while (t--){
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        int c = 0;

        char index;
        int white = 0;
        int adj = 0;

        for (int i = 0; i < n; i++){
            c = 0;
            for (int j = 0; j < m; j++){
                cin >> index;

                if (index == '.') {
                    c ++;
                    white ++;
                }
                else c = 0;

                if (c == 2){
                    adj ++;
                    c = 0;
                }

            }

        }
        if (2 * x < y) cout << x * white << endl;
        else cout << x * (white - 2 * adj) + y * adj << endl;


    }
    return 0;
}
