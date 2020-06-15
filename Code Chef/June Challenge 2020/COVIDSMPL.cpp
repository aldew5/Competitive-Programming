/*
Aldew
PROB: Covid Sampling (Challenge)
CLASSIFICATION: Math. matrices
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
#define ll long long int
#define ull unsigned long long


using namespace std;

/*
Niave solution that just looks at each cell individually
until it's run out of queries.
*/
const int Q = 18000;

int main()
{
    int T;
    cin >> T;
    while (T--){
        int n, p;
        cin >> n >> p;

        int m[n][n] = {0};


        bool run = true;
        int it, c = 0;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < n; j++){
                cout << 1 << " " << i + 1<< " " << j + 1 << " " << i + 1 << " " << j + 1 << endl;
                cin >> it;

                if (it == 1) m[i][j] = 1;
                else m[i][j] = 0;
                c ++;

                if (c == Q) {
                    run = false;
                    break;
                }
            }
            if (!run) break;
        }
        cout << 2 << endl;
        for (int i = 0; i < n; i++){
            for (int j  = 0; j < n; j++){
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
        int res;
        cin >> res;
        if (res == -1) break;
    }



    return 0;
}
