/*
Aldew
PROB: Matched Brackets
CLASSIFICATION: Stacks
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
#define ull unsigned long long

using namespace std;

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    ll n;
    cin >> n;
    vector<int> a(n);

    for (auto& it : a) cin >> it;

    ll maxd = 0, maxl = 0, posd, posl;

    stack<int> st;
    ll c = 0;
    for (int i = 0; i < a.size(); i++){
        if (a[i] == 1) st.push(1);
        else st.pop();

        if (st.size() > maxd){
            maxd = st.size();
            posd = i + 1;
        }

        if (st.size() != 0) c ++;

        else {
            c ++;
            if (c > maxl) {
                maxl = c;
                posl = (i+1) - c + 1;
            }
            c = 0;
        }

    }
    cout << maxd << " " << posd << " " << maxl << " " << posl << endl;

}





