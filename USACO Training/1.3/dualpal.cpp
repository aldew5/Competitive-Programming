/*
ID: alec3
LANG: C++14
PROG: dualpal
CLASSIFICATION: brute force
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

string to_base(int number,int base){
	string bases = "0123456789ABCDEFGHIJK";
	string result = "";

	while(number > 0){
		result = bases[number % base] + result;
		number /= base;
	}
	return result;
}

bool isPal(string s){
    string rev = string(s.rbegin(), s.rend());
    if (rev == s) return true;
    else return false;
}

int main()
{
    ofstream fout("dualpal.out");
    ifstream fin("dualpal.in");

    int n, s;
    fin >> n >> s;

    int c = 0;
    int co, i = s + 1;

    while (c < n){

        for (int b = 2; b <= 10; b++){
            if (isPal(to_base(i, b))) co ++;
        }

        if (co >= 2){
            cout << i << endl;
            fout << i << endl;
            c ++;
        }
        co = 0;
        i ++;

    }



    return 0;
}

