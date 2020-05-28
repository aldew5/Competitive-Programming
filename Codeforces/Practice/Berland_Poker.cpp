/*
Aldew
PROB: Berland Poker
Classification: Brute force, math, greedy
Difficulty:
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;


int main()
{
    int t;
    cin >> t;

    while (t--){
        double n, m, k;
        cin >> n >> m >> k;
        int score;

        if (n/k <= m) score = n/k;
        else score = m;

        // split the remaining jokers as sparsely as possible
        double sec = ceil((m-score)/(k-1));

        if (score > sec){
            cout << score - sec << endl;
        }
        else cout << 0 << endl;

    }
    return 0;
}

