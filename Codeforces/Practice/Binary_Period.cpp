/*
Aldew
PROB: Binary Period
CLASSIFICATION: Constructive algorithms, strings
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
Either there is all of one type of number in t
in which case the smallest period is 1 and you
can output a sequence of that number.

Or there are different numbers in which case the smallest
period is two and you must output an alternating sequence.
*/
int main()
{
    int T;
    cin >> T;
    while (T--){
        string t;
        cin >> t;

        bool same = true;
        char n = t[0];

        for (int i = 0; i < t.size(); i++){
            if (t[i] != n){
                same = false;
            }
        }

        if (same){
            string ans = "";
            for (int i = 0; i < t.size() + 1; i++){
                ans += n;
            }
            cout << ans << endl;
        }
        else {
            string ans = "";
            char last = t[0];

            for (int i = 0; i < t.size() * 2; i++){
                if (last == '0'){
                    ans += '1';
                    last = '1';
                }
                else {
                    ans += '0';
                    last = '0';
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
