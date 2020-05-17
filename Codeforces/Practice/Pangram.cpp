/*
Aldew
PROB: "Pangram"
CLASSIFICATION: Ad hoc, Strings
DIFFICULTY: 800


*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;


int main()
{
   int n;
   cin >> n;

   string s;
   cin >> s;

   vector<char> used;
   bool add;
   char c;

   for (int i = 0; i < n; ++i){
        c = s[i];
        add = true;
        for (int j = 0; j < used.size(); ++j){
            if (tolower(c) == used[j]){
                add = false;
            }
        }
        if (add) used.push_back(tolower(c));
   }

    if (used.size() == 26) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
