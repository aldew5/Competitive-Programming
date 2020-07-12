/*
Aldew
PROB: Up and Down
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
    int a, b, c, d, s;
    cin >> a >> b >> c >> d >> s;

    int co = 0;
    int apos = 0, bpos = 0;
    while (co < s){
        if (co + a <= s){
            apos += a;
            co += a;
        }
        else {
            apos += (s-co);
            break;
        }

        if (co + b <= s){
            apos -= b;
            co += b;
        }
        else {
            apos -= (s-co);
            break;
        }

    }

    co = 0;
    while (co < s){
        if (co + c <= s){
            bpos += c;
            co += c;
        }
        else {
            bpos += (s-co);
            break;
        }

        if (co + d <= s){
            bpos -= d;
            co += d;
        }
        else {
            bpos -= (s-co);
            break;
        }

    }

    if (apos > bpos) cout << "Nikky" << endl;
    else if (apos == bpos) cout << "Tied" << endl;
    else cout << "Byron" << endl;
}
