/*
Aldew
PROBLEM D: Polygons
*/
 
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <map>
 
using namespace std;
 

int main()
{
    int t;
    cin >> t;
 
    while (t--){
        int n;
        cin >> n;
        string line;
        vector<int> pos;
        bool good = true;
 
        while (n > 0){
            line = "";
            cin >> line;
 
            // check prev
            for (int i = pos.size() -1; i >= 0; i--){
                if (line[pos[i]] != '1'){
                    good = false;
                }
            }
            pos.clear();
 
            for (int i = 0; i + 1 <= line.size(); i++){
                if (line[i] == '1' && line[i+1] == '0') {
                    pos.push_back(i);
                }
            }
            n --;
        }
        if (good) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
 
}
