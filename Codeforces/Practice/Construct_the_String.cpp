/*
Aldew
PROB: "Construct the String"
CLASSIFICATION: Constructive
DIFFICULTY: 1000
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <map>

using namespace std;


/*
Just repeat a pattern of length b
*/
int main()
{
    int t;
    cin >> t;
    string alpha = "abcdefghijklmnopqrstuvwxyz";

    while (t--){
        int n, a, b;
        cin >> n >> a >> b;
        string pattern;

        if (a == 1) pattern = "a";
        else pattern = alpha.substr(0, b);
        string ans = "";

        for (int i = 0; i < floor(n/b); i++){
            ans += pattern;
        }

        if (ans.size() < n){
            ans += pattern.substr(0, n-ans.size());
        }

        cout << ans << endl;
    }
    return 0;

}
