/*
Aldew
PROB: Level Statistics
CLASSIFICATION: math, implementation
DIFFICULTY: 1200
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
        int n;
        cin >> n;
        bool good = true;

        int plays, clears, prevp = -1, prevc = -1, dif;
        for (int i = 0; i < n; i++){
            cin >> plays >> clears;

            dif = clears - prevc;

            if (prevp + dif > plays) good = false;
            else if (plays < prevp || clears < prevc) good = false;

            prevp = plays;
            prevc = clears;
        }

        if (good) cout << "YES" << endl;
        else cout << "NO" << endl;

  }

    return 0;
}
