/*
Aldew
PROBLEM: Wierd Walk
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
    long long n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    long long ad = 0, bd = 0;
    long long ans = 0;

    for (auto & it : a) cin >> it;
    for (auto & it : b) cin >> it;

    bool same = true;
    for (int i = 0; i < n; i++){
        if (same && a[i] == b[i]) {
            ans += a[i];
            ad += a[i];
            bd += a[i];
        }
        else if (a[i] != b[i]){
            ad += a[i];
            bd += b[i];
        }

        if (ad == bd){
            same = true;
        }
        else same = false;

    }
    cout << ans << endl;

  }

    return 0;
}
