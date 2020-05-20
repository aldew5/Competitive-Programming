/*
Aldew
PROB: "Little Artem"
Classification: Constructive algorithms
Difficulty: 1000
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

/*
One white in the corner with blacks around it
*/

int main()
{
    int t;
    cin >> t;

    while (t--){

        int rows, cols;
        cin >> rows >> cols;

        vector<string> ans;
        string b_row = "";

        for (int i = 0; i < cols; i++){
            b_row += "B";
        }

        for (int i = 0; i < rows; i++){
            if (i != rows-1){
                ans.push_back(b_row);
            }
            else {
                b_row.erase(b_row.size() -1);
                string w_row = b_row + "W";
                ans.push_back(w_row);
                break;
            }
       }
        for (int i = 0; i < ans.size(); i++){
            cout << ans[i] << endl;
        }
    }

    return 0;
}
