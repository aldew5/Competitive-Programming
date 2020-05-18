/*
Aldew
PROB: "Keanu Reeves"
CLASSIFICATION: Ad hoc, Strings
DIFFICULTY: 800


*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

/*
Output two strings of odd length (half the string)
*/

bool isGood(string s){
    int one_count = 0;
    int zero_count = 0;

    for (int i = 0; i < s.size(); i++){
        if (s[i] == '0') zero_count ++;
        else if (s[i] == '1') one_count ++;
    }

    if (one_count == zero_count) return false;
    else return true;

}

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (s.size() == 1) {
        cout << 1 << endl;
        cout << s << endl;
    }
    else if(isGood(s)){
        cout << 1 << endl;
        cout << s << endl;
    }
    else {

        string sub1 = "";
        string sub2 = "";

        for (int i = 0; i < n -1; i++){
            sub1 += s[i];
        }
        sub2 += s[n-1];

        cout << 2 << endl;
        cout << sub1 << " " << sub2 << endl;
    }

    return 0;
}
