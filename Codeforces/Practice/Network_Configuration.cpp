/*
Aldew
PROB: "Network Configuration"
CLASSIFICATION: Greedy
DIFFICULTY: 900
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

/*
Sort the list in decreasing
order and pick the kth highest one.
*/

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> comps(n);
    for (auto& it : comps) cin >> it;

    sort(comps.rbegin(), comps.rend());

    // subtract one from k because of zero indexing
    cout << comps[k -1] << endl;

}
