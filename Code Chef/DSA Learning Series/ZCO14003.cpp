/*
Aldew
PROB: Smart Phone
CLASSIFICATION: Brute Force 
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

// Runs in O(n)

int main()
{
    long long n;
    cin >> n;

    vector<int> a;
    while (n --){
        long long it;
        cin >> it;
        a.push_back(it);
    }
    sort(a.begin(), a.end());

    long long m = 0;
    for (long long i = 0; i < a.size(); i++){
        if ((a[i] * (a.size() - i)) > m) m = a[i] * (a.size() - i);
    }
    cout << m << endl;
}
