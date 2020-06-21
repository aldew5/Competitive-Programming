/*
Aldew
PROB: Save Konoha
CLASSIFICATION: Priority Queue
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
 
 
ll myXOR(ll x, ll y)
{
    ll res = 0; // Initialize result
 
    // Assuming 32-bit Integer
    for (int i = 31; i >= 0; i--)
    {
       // Find current bits in x and y
       bool b1 = x & (1 << i);
       bool b2 = y & (1 << i);
 
        // If both are 1 then 0 else xor is same as OR
        bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);
 
        // Update result
        res <<= 1;
        res |= xoredBit;
    }
    return res;
}
/*
Use the myXOR function as the normal "^" operator doesn't 
work for larger numbers.  myXOR doesn't use the "^" operator.
*/
 
 
int main()
{
    io;
    ll n;
    cin >> n;
 
    vector<int> a;
    ll it;
 
    ll s = -1;
    for (ll i = 0; i < n; i++){
        cin >> it;
 
        if (s != -1){
            s = myXOR(s, it);
        }
        else s = it;
        a.push_back(it);
    }
 
    ll val;
    for (ll i = 0 ; i < n; i++){
 
        val = myXOR(s, a[i]);
 
        cout << val << " ";
    }
    cout << endl;
 
 
    return 0;
}
