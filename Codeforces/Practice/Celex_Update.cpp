/*
Aldew
PROB: Celex Update
CLASSIFICATION: math
DIFFICULTY: 1600
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
Each x has a bend and for each string of xs
there are (y2 - y1) different ys in the chain.
Then add the x over, y down sum.
*/
int main()
{
  int t;
  cin >> t;

  while (t--){
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << (x2 - x1) * (y2 - y1) + 1 << endl;
    }

    return 0;
}

