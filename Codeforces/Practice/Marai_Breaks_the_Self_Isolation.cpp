/*
Aldew
PROB: Maria Breaks the Self Isolation
CLASSIFICATION: Greedy, sortings
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

*/
int main()
{
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& it : a) cin >> it;

    int c = 1;
    sort(a.begin(), a.end());
    int temp = 0, c2 = 0;

    for (int i = 0; i < a.size(); i++){
        if (a[i] <= c) c ++;
        else c2 ++;

        // look for an all at once group
        if (a[i] <= (c2 + c -1)) {
            c += c2;
            c2 = 0;
        }
    }



    cout << c << endl;
  }
  return 0;
}
