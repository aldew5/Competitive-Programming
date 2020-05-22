/*
Aldew
PROB: "Orac and Factors"
CLASSIFICATION: Math
DIFFICULTY: 90
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <map>

using namespace std;


/*
If n is even just add 2 k times.
If n is odd find the first value then
add 2 k -1 times
*/
int main()
{
    int t;
    cin >> t;

    while (t--){
        int n, k;
        cin >> n >> k;

        if (n % 2 == 0){
            cout << n + 2 * k << endl;
        }
        else {
            int div;
            for (int i = 3; i <= n; i++){
                if (n % i == 0){
                    div = i;
                    break;
                }
            }
            cout << n + div + 2 * (k-1) << endl;
        }
    }
    return 0;

}
