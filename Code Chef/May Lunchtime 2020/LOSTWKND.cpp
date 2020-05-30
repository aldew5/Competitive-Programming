/*
Aldew
PROBLEM: Lost Weekend
CLASSIFICATION:
DIFFICULTY:
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


int main()
{
  int t;
  cin >> t;

  while (t--){
    int a1, a2, a3, a4, a5, p;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> p;

    double sum = 0;
    sum += a1 * p + a2 * p + a3 * p + a4 * p + a5 * p;

    if (sum/5 <= 24) cout << "No" << endl;
    else cout << "Yes" << endl;

  }

    return 0;
}
