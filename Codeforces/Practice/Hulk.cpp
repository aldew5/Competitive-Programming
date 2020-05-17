/*
Aldew
PROB: "Hulk"
CLASSIFICATION: Ad hoc
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

     string ans = "";

     string base_hate = "I hate it";
     string base_love = "I love it";

     string hate = "I hate that";
     string love = "I love that";

     char type = 'h';

     for (int i = 0; i < n; ++i){
        if (i != n-1){
            if (type == 'h'){
                ans += hate + " ";
                type = 'l';
            }
            else {
                ans += love + " ";
                type = 'h';
            }
        }
        else {
            if (type == 'h'){
                ans += base_hate;
            }
            else {
                ans += base_love;
            }
        }
     }
        cout << ans << endl;

    return 0;
}
