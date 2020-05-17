/*
Aldew
PROB: "Vanya and Fence"
CLASSIFICATION: Ad hoc
DIFFICULTY: 800


*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;


int main()
{
    int n;
    int h;
    cin >> n >> h;
    vector<int> heights(n);

    for (auto&it : heights) cin >> it;

    int min_width = n;

    for (int i = 0; i < n; ++i){
        if (heights[i] > h) min_width ++;
    }
    cout << min_width << endl;
    return 0;
}
