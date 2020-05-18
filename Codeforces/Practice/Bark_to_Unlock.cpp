/*
Aldew
PROB: "Bark to Unlock"
CLASSIFICATION: Brute force, Strings
DIFFICULTY: 900
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <string>

using namespace std;
/*
Use brute force to check all possible combinations
of the strings
*/

int main()
{
    int n;
    string pass;
    cin >> pass >> n;
    vector<string> words(n);

    string word;
    for (auto& it : words) cin >> it;


    bool worked = false;
    for (int i = 0; i < words.size(); ++i){
        for (int j = 0; j < words.size(); ++j){
            // the substring pass was found in the concatinated barks
            if ((words[j] + words[i]).find(pass) != std::string::npos ||
                (words[i] + words[j]).find(pass) != std::string::npos){

                worked = true;
                break;
            }
        if (worked) break;
        }
    }
    if (worked) cout << "YES" << endl;
    else cout << "NO" << endl;


}

