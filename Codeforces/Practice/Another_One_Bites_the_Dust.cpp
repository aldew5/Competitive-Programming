/*
Aldew
PROB: "Another One Bites the Dust"
CLASSIFICATION: Ad hoc, Strings
DIFFICULTY: 800


*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

/*
c strings can always be used. We can only used max(a, b) + 1 
strings though.
*/

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;

    long long ans = c * 2 + min(a, b) * 2;

    if (abs(a-b) >= 1) ans ++;

    cout << ans << endl;

    return 0;
}

