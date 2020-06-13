/*
Aldew
PROB: Laddu
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
#define ll long long


using namespace std;


int main()
{
    int T;
    cin >> T;
    while (T--){
        int n;
        string org;
        cin >> n >> org;

        int laddus = 0, it;
        string act;
        while (n --){
            cin >> act;
            if (act == "BUG_FOUND" || act == "CONTEST_WON"){
                cin >> it;
                if (act == "CONTEST_WON") {
                    if (it < 20) laddus += 300 + 20 - it;\
                    else laddus += 300;
                }
                else laddus += it;
            }
            else if (act == "TOP_CONTRIBUTOR") laddus += 300;
            else if (act == "CONTEST_HOSTED") laddus += 50;

        }

        if (org == "NON_INDIAN") cout << laddus/400 << endl;
        else cout << laddus/200 << endl;
    }

    return 0;
}
