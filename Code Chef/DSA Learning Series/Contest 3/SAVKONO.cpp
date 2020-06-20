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

int main()
{
    io;
    int t;
    cin >> t;
    while (t--){
        ll n, z;
        cin >> n >> z;

        priority_queue<int> q;
        ll a;
        for (ll i = 0; i < n; i++){
            cin >> a;
            q.push(a);
        }

        ll x, c = 0;
        while (q.top() != 0 && z > 0){
            z -= q.top();
            x = q.top();
            x /= 2;
            q.pop();
            q.push(x);
            c ++;

        }
        if (z <= 0) cout <<  c << endl;
        else cout << "Evacuate" << endl;
    }


    return 0;
}





