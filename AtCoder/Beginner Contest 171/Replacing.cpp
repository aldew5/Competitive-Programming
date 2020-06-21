/*
Aldew
PROB: Replacing
CLASSIFICATION: maps
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

/*
Store the frequency of each integer in a map and use
that to update the sum
*/
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
    ll n;
    cin >> n;
 
    ll it;
    ll s = 0;
 
    map<int, int> m;
    for (int i = 0; i < n; i++){
        cin >> it;
        s += it;
        m[it] ++;
    }
 
    ll q;
    cin >> q;
 
    ll b, c;
    while (q--){
        cin >> b >> c;
 
        //cout << "here" << m[b] << endl;
        s -= (b * m[b]);
        s += (c * m[b]);
 
        m[c] += m[b];
        m[b] = 0;
 
        cout << s << endl;
    }
 
    return 0;
}
