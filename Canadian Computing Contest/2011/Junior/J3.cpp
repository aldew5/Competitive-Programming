/*
Aldew
PROB: Sumac Sequences
CLASSIFICATION: Implementation, math
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
    int t1, t2;
    cin >> t1;
    cin >> t2;

    int val;

    int ans = 2;
    while (true){
        val = t1 - t2;

        t1 = t2;
        t2 = val;

        ans ++;
        if (val < 0) {
            ans --;
            break;
        }
    }
    cout << ans << endl;

 	return 0;
}
