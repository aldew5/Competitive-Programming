/*
Aldew
PROB: Alarm Clock
Classification: math
Difficulty: 900
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>

#define ll long long

using namespace std;


int main()
{
    int t;
    cin >> t;

    while (t--){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        ll total = b;
        if (total < a && (c-d) <= 0) cout << -1 << endl;
        else {
            if (total >= a) cout << total << endl;
            else {
                double dif = c -d;
                ll ans = b;

                ans += ceil((a-b)/dif) * c;
                cout << ans << endl;
            }
        }


    }
    return 0;
}


