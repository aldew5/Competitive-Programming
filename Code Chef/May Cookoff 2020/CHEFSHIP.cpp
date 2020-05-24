/*
Aldew
PROBLEM: Chef, Chefina and Their Freindship
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
        string s;
        cin >> s;

        string sub1, sub2;
        int l2;
        int ans = 0;
        for (int l = 1; l <= s.size(); l++){
            if ((s.size() - 2 * l) % 2 == 0 && 2 * l + 1 <= s.size()){
                sub1 = s.substr(0, l);
                l2 = (s.size() - 2 * l) != 0 ? (s.size() - 2 * l)/2 : 0;
                sub2 = s.substr(2 * l, l2);

                //cout << sub1 << " " << s.substr(0 + l, l) << " " <<  sub2 << " " << s.substr(l * 2 + l2, l2) << endl;
                if (sub1 == s.substr(l, l) && sub2 == s.substr(l * 2 + l2, l2)){
                    ans ++;
                }
            }
        }
        cout << ans << endl;

    }

    return 0;

}
