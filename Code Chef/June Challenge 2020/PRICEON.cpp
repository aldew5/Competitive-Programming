/*
Aldew
PROB: Chef and Price Control
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

using namespace std;

/*
If the range is 0 it's impossible
Otherwise check if the final position in within range
as you can just walk back and forth for the rest.
*/
int main()
{
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;

        int ans = 0;
        int p;
        for (int i = 0; i < n; i++){
            cin >> p;
            if (p > k) ans += p -k;
        }
        cout << ans << endl;

    }
    return 0;
}
