/*
Aldew
PROB: Crane and Turtle
CLASSIFICATION: Math
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
 
 
using namespace std;
 
 
int main()
{
    int x, y;
    cin >> x >> y;
 
    if (4*x >= y && ((4*x -y) % 2) == 0 && ((4*x -y) /2) <= x) cout << "Yes" << endl;
    else cout << "No" << endl;
}
