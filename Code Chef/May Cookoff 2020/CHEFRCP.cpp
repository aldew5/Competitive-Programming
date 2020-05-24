Aldew
PROBLEM: Chef and Recipe
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <map>

using namespace std;

/*

*/
int main()
{
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& it : a) cin >> it;

        map<int, int> quant;
        vector<int> used;
        bool good = true;
        int last;

        for (int i = 0; i < a.size(); i++){
            for (int j = 0; j < used.size(); j++){
                if (a[i] == used[j]){
                    good = false;
                    break;
                }
            }
            //if (!good) break;

            if (i + 1 < a.size() && a[i] != a[i +1]){
                used.push_back(a[i]);
            }
            quant[a[i]] ++;
            last = a[i];

        }
        used.push_back(last);

        if (!good){
            cout << "NO" << endl;
        }
        else {
            vector<int> nums;
            for (int i = 0; i < used.size(); i++){
                for (int j = 0; j < nums.size(); j++){
                    if (quant[used[i]] == nums[j]){
                        good = false;
                        break;
                    }
                }
                nums.push_back(quant[used[i]]);
                if (!good) break;
            }
            if (good) cout << "YES" << endl;
            else {
                cout << "NO" << endl;
            }
        }


    }


    return 0;

}
