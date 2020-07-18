/*
ID: alec3
LANG: C++14
PROG: Sounds Fishy!
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

// NOTE: Grader giving wrong answer on test 3 even though output is correct
int main()
{
    //ifstream fin("frac1.in");
	//ofstream fout("frac1.out");
	int a, b, c, d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;

	if (a < b && b < c && c < d) cout << "Fish Rising" << endl;
	else if (a == b && b == c && c == d) cout << "Constant Depth" << endl;
	else if (a > b && b > c && c > d) cout << "Fish Diving" << endl;
	else cout << "No Fish" << endl;


    return 0;

}
