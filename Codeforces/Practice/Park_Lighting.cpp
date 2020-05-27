/*
Aldew
PROB: Park Lighting
CLASSIFICATION: math
DIFFICULTY: 800
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
If the area is odd then subtract one of the squares
to get and (n-1)*1 rectangle and a (m-1)*n regtangle
both with even areas.
*/
int main()
{
  int t;
  cin >> t;
  while (t--){
    int m, n;
    cin >> m >> n;

    if (m % 2 != 0 && n & 2 != 0) cout << 1 + (n-1) /2 + (n * (m-1))/2 << endl;
    else cout << m * n/2 << endl;
  }
  return 0;
}
