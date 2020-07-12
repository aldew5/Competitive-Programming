/*
Aldew
PROB: Punchy
CLASSIFICATION: Implementation
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

int main()
{
    io;
    int n, num;
    int a = 0, b = 0;
    char let, let2;

    while (true){
        cin >> n;
        if (n == 1){
            cin >> let >> num;
            if (let == 'A') a = num;
            else b = num;
        }
        else if (n == 2){
            cin >> let;
            if (let == 'A') cout << a << endl;
            else cout << b << endl;
        }
        else if (n==3){
            cin >> let >> let2;
            if (let == 'A' && let2 == 'B') a = a +b;
            else if (let == 'A' && let2 == 'A') a = 2 *a;
            else if (let == 'B' && let2 == 'B') b = 2*b;
            else b = a+b;
        }
        else if (n==4){
            cin >> let >> let2;
            if (let == 'A' && let2 == 'B') a = a *b;
            else if (let == 'A' && let2 == 'A') a = a*a;
            else if (let == 'B' && let2 == 'B') b = b*b;
            else b = a *b;
        }
        else if (n == 5){
            cin >> let >> let2;
            if (let == 'A' && let2 == 'B') a = a-b;
            else if (let == 'A' && let2 == 'A') a = a - a;
            else if (let == 'B' && let2 == 'B') b = b - b;
            else b = b -a;
        }
        else if (n==6){
            cin >> let >> let2;
            if (let == 'A' && let2 == 'B') a = a/b;
            else if (let == 'A' && let2 == 'A') a = 1;
            else if (let == 'B' && let2 == 'B') b = 1;
            else b = b/a;
        }
        else break;

    }

    return 0;
}
