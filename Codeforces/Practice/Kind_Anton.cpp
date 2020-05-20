/*
Aldew
PROB: "Kind Aton"
Classification: Greedy, implementation
Difficulty: 1100
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

/*
If there are no ones in a then you can increase
integers. Likewise with negatives.

Since j > i you must have a negative/ positive in a previous
position to the int that needs to be changed.

*/

int main()
{
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        bool good = true;

        for (auto& it : a) cin >> it;
        for (auto& it : b) cin >> it;

        bool possp = false;
        bool possn = false;

        for (int i = 0; i < n; i++){

            // difference
            if (a[i] != b[i]){
                // a[i] needs to be decremented
                if (b[i] - a[i] < 0 && !possn){
                    good = false;
                    break;
                }
                else if (b[i] - a[i] > 0 && !possp){
                    good = false;
                    break;
                }
            }

            if (a[i] == 1) possp = true;
            else if (a[i] == -1) possn = true;

            if (possp && possn) break;
        }
        if (good) cout << "YES" << endl;
        else cout << "NO" << endl;


    }

    return 0;
}
