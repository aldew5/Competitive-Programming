/*
Aldew
PROB: Who Has Seen the Wind?
CLASSIFICATION: Implementation
DIFFICULTY:
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main()
{
    io;
    int h, m;
    cin >> h;
    cin >> m;

    int ans;

    bool good = false;
    for (int t = 1; t <= m; t ++){
        if (-6 * pow(t, 4) + h * pow(t, 3) + 2 * pow(t, 2) + t <= 0){
            good = true;
            ans = t;
            break;

        }
    }
    if (good) {
        cout << "The balloon first touches ground at hour:" << endl;
        cout << ans << endl;
    }
    else cout << "The balloon does not touch ground in the given time." << endl;

 	return 0;
}
