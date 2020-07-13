/*
Aldew
PROB: Which Alien?
CLASSIFICATION: Implementation
DIFFICULTY:
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;

using namespace std;


int main()
{
    io;
    int a, eye;
    cout << "How many antennas?" << endl;
    cin >> a;
    cout << "How many eyes?" << endl;
    cin >> eye;

    if (a >= 3 && eye <= 4) cout << "TroyMartian" << endl;
    if (a <= 6 && eye >= 2) cout << "VladSaturnian" << endl;
    if (a <= 2 && eye <= 3) cout << "GraemeMercurian" << endl;

 	return 0;
}
