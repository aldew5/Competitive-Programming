/*
Aldew
PROB: Exercising Walk
CLASSIFICATION: Implementation, greedy, math
DIFFICULTY: 1100
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

/*
If the range is 0 it's impossible
Otherwise check if the final position in within range
as you can just walk back and forth for the rest.
*/
int main()
{
    int t;
    cin >> t;
    while (t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        bool worked;
        if ((abs(x1 - x2) == 0) && (a != 0 || b != 0)) worked = false;
        else if ((abs(y1 -y2) == 0) && (c != 0 || d != 0)) worked = false;
        else worked = true;

        if (worked){
            if ((x - a + b) >= x1 && (x - a + b) <= x2){
                if ((y -c + d) >= y1 && (y -c + d) <= y2){
                    worked = true;
                }
                else worked = false;
            }
            else worked = false;
        }

        if (worked) cout << "Yes" << endl;
        else cout << "No" << endl;

    }
    return 0;
}
