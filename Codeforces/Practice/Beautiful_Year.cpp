/*
Aldew
PROB: "Beautiful Year"
CLASSIFICATION: Ad hoc
DIFFICULTY: 800


*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

bool test(int y){
    string s = to_string(y);
    vector<char> used;

    for (int i = 0; i < s.size(); ++i){
        for (int j = 0; j < used.size(); ++j){
            if (s[i] == used[j]){
                return false;
            }
        }
        used.push_back(s[i]);
    }
    return true;
}

int main()
{
    int y;
    cin >> y;
    y ++;
    bool look = true;

    while (look){
        if (test(y) == false) y += 1;
        else look = false;
    }
    cout << y << endl;

    return 0;
}




