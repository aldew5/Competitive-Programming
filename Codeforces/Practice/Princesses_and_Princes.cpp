/*
Aldew
PROB: Princesses and Princes
CLASSIFICATION: brute force, graphs, greedy
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


int main()
{
  int t;
  cin >> t;

  while (t--){
        int n;
        cin >> n;

        int high = 0;
        vector<int> used;
        bool isUsed, improve = true, poss = true;
        int imin = 0;

        for (int i = 0; i < n; i++){
            int k;
            cin >> k;
            vector<int> g;

            int index, small;
            for (int j = 0; j < k; j++){
                cin >> index;
                isUsed = false;
                for (int w = 0; w < used.size(); w++){
                    if (used[w] == index){
                        isUsed = true;
                        break;
                    }
                }
                if (!isUsed) g.push_back(index);

                if (index > high) high = index;
            }

            small = -1;
            for (int j = 0; j < g.size(); j++){
                if (small == -1 || g[j] < small) small = g[j];
            }
            if (g.size() == 0) {
                imin = i + 1;
                improve = true;
            }

            if (small != -1 && small != 0) used.push_back(small);
        }
        if (used.size() == n) poss = false;

        if (improve && poss) {
            sort(used.begin(), used.end());
            int c = -1;

            for (int i = 0; i < used.size(); i++){
                if (i + 1 != used[i]) {
                    c = i + 1;
                    break;
                }
            }

            if (c == -1) c = n;

            cout << "IMPROVE" << endl;
            cout << imin << " " << c << endl;
        }
        else cout << "OPTIMAL" <<  endl;
  }

    return 0;
}
