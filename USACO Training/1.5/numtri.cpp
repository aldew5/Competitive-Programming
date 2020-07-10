/*
ID: alec3
LANG: C++14
PROG: numtri
CLASSIFICATION: brute force
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;

using namespace std;


int main() {

	ifstream fin("numtri.in");
	ofstream fout("numtri.out");

	int best[1000], old[1000];

    int r;
    fin >> r;

    for (int i = 0; i < 1000; i++){
        best[i] = 0;
    }
    int it;
    for (int i = 1; i <= r; i++){
        // copy the bytes from best to old where sizeof
        // is the number of bytes to copy
        memmove(old, best, sizeof old);
        // read a row
        for (int j = 0; j < i; j++){
            fin >> it;
            // set the best to the best of the previous rows plus the
            // newest integer
            if (j == 0) best[j] = old[j] + it;
            // old + new int or the previous old + new int
            else best[j] = max(old[j], old[j-1]) + it;
        }
    }

    int ans = 0;
    // find the greatest answer
    for (int i = 0; i < r; i++){
        if (best[i] > ans) ans = best[i];
    }
    fout << ans << endl;


    return 0;

}
