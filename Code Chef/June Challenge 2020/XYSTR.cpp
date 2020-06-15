/*
Aldew
PROB: Chef and String
CLASSIFICATION: Implementation
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
        string s;
        cin >> s;

        int pairs = 0;
        for (int i = 0; i < s.size(); i++){
            if (i + 1 < s.size() && s[i] != s[i+1]){
                pairs ++;
                i ++;
            }
        }
        cout << pairs << endl;

    }
    return 0;
}
