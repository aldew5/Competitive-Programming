/*
Aldew
PROB: "Frog Jumps"
CLASSIFICATION: Binary serach, Data structures, dfs, greedy.
                implementation
DIFFICULTY: 1100
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <map>

using namespace std;


/*
It only makes sense to move right so find the
greatest difference between two R's in the string
or the last R and n+1.
*/
int main()
{
    // construct a vector of the pos of right moves
    int t;
    cin >> t;

    while (t--){
        string moves;
        cin >> moves;
        vector<int> pos;
        pos.push_back(0);

        for (int i = 0; i < moves.size(); i++){
            if (moves[i] == 'R'){
                pos.push_back(i + 1);
            }
        }
        pos.push_back(moves.size() + 1);
        int ans = 0;
        for (int i = 0; i + 1< pos.size(); i++){
            if (abs(pos[i] - pos[i+1]) > ans){
                ans = abs(pos[i] - pos[i+1]);
            }
        }
        cout << ans << endl;
    }
    return 0;

}
