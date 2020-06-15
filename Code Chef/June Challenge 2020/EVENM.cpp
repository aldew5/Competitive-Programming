/*
Aldew
PROB: Even Matrix
CLASSIFICATION: Implementation, math, matrices
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
//#define long long ll;

using namespace std;



int twoCount(int n){
    long long w = n;
    long long c = 0;

    while (w % 2 == 0){
        w /= 2;
        c ++;
    }

    return c;
}

int main()
{
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;

        if (n % 2 != 0){
            int c  = 1;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    cout << c << " ";
                    c++;
                }
                cout << endl;
            }
        }
        else {
            int c = 1;
            bool spin = false;
            vector<int> row;
            for (int i = 0; i < n; i++){
                row.clear();
                for (int j = 0; j < n; j++){
                    row.push_back(c);
                    c ++;
                }
                if (spin){
                    sort(row.rbegin(), row.rend());
                    spin = false;
                }
                else spin = true;

                for (int j = 0; j < row.size(); j++){
                        cout << row[j] << " ";
                    }
                    cout << endl;
            }
        }
    }
    return 0;
}
