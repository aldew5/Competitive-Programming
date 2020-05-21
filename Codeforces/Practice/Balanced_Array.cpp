/*
Aldew
PROB: "Balanced Array"
Classification: Constructive, math
Difficulty: 800
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

/*
Add n/2 multiples of 2, then n/2 -1 odd numbers.
If the difference between the sums of the two is odd
then it's possible.
*/


int main()
{
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        int sum1 = 0;
        int sum2 = 0;
        vector<int> ans;

        for (int i = 1; i <= n/2; i++){
            sum1 += i * 2;
            ans.push_back(i * 2);
        }
        for (int i = 1; i < n/2; i ++){
            sum2 += i * 2 -1;
            ans.push_back(i * 2 -1);
        }

        int dif = sum1 - sum2;
        if (dif > 0 && dif %2 != 0) {
                sum2 = sum1;
                ans.push_back(dif);

                cout << "YES" << endl;

                string s = "";
                for (int i = 0; i < ans.size(); i++){
                    s += to_string(ans[i]) + " ";
                }
                cout << s << endl;
        }
        else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
