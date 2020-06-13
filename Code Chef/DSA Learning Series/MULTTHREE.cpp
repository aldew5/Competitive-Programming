/*
Aldew
PROB: Multiple of Three
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
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);


    int t;
    cin >> t;

    while (t--){
        ll k,d,e;
        cin>> k >> d >>e;
        ll f = d + e;
        ll a= 1;
        ll ans = f;
        k -= 2;

        if(k > 0){
        	ans+=f%10;
        	k--;
		}

        ll c = k/4;
        ll cc = k%4;

        ans += c*((f*2)%10+(f*4)%10+(f*8)%10+(f*16)%10);

        if(cc == 1) ans+=((f*2)%10);
        else if(cc == 2) ans+=((f*2)%10+(f*4)%10);
        else if(cc == 3) ans += ((f*2)%10+(f*4)%10+(f*8)%10);

        if(ans % 3 == 0) cout << "YES" << endl;
        else cout<<"NO" << endl;
    }
}

