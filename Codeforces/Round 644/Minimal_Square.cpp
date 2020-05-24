
/*
Aldew
PROBLEM A: Minimal Square
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
        int a, b;
        cin >> a >> b;
        int mini;
        char let;
 
        // single side
        if (b < a){
            mini = 2 * b;
            let = 'a';
        }
        else {
            mini = 2 *a;
            let = 'b';
        }
 
        int i = 1;
        while (i < mini){
            i++;
        }
        if (let == 'b'){
            while (i < b){
                i++;
            }
        }
        else {
            while (i < a){
                i ++;
            }
        }
        cout << i * i << endl;
    }
    return 0;
 
}
