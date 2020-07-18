/*
ID: alec3
LANG: C++14
PROG: Speed Fines are not Fine!
CLASSIFICATION: implementation
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

// NOTE: solution is correct but doesn't work with the grader

int main()
{
    //ifstream fin("frac1.in");
	//ofstream fout("frac1.out");
	int limit;
    cout << "Enter the speed limit:  ";
    cin >> limit;
    int speed;
    cout << "Enter the recorded speed or the car:  ";
    cin >> speed;

    if (speed <= limit) cout << "Congratulations, you are within the speed limit!" << endl;
    else{
        if (speed - limit <= 20)
        cout << "You are speeding and your fine is $100." << endl;

        else if (speed - limit > 20 && speed - limit <= 30)
            cout << "You are speeding and your fine is $270." << endl;

        else cout << "You are speeding and your fine is $500." << endl;
    }




    return 0;

}
