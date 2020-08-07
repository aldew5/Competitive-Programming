/*
Aldew
PROB: Alphabet
CLASSIFICATION: Implementation
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
#include <stack>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
 
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
//void io()
//{
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
//}
 
vector <int> factors(int x) {
    vector <int> result;
    int i = 1;
    while(i*i <= x) {
        if(x % i == 0) {
            result.push_back(i);
            if(x/i != i) {
                result.push_back(x/i);
            }
        }
        i++;
    }
    return result;
}
 
int main()
{
    io;
    char c;
    cin >> c;
 
    if (isupper(c)){
        cout << 'A' << endl;
    }
    else {
        cout << 'a' << endl;
    }
  return 0;
}
