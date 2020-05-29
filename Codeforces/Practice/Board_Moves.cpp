/*
Aldew
PROB: Board Moves
CLASSIFICATION: math
DIFFICULTY: 1000
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
Move peices to the center.
*/
int main()
{
  int t;
  cin >> t;

  while (t--){
        long long n;
        cin >> n;
        long long ans = 0;

        if (n == 1) cout << 0 << endl;
        else {
            while (n > 0){
                ans += ((n-1)/2) * (n * n - ((n-2) * (n-2)));
                n-= 2;
            }
            cout << ans << endl;
        }
    }

    return 0;
}




