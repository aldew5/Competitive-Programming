/*
ID: alec3
LANG: C++14
PROG: pprime
CLASSIFICATION: brute force
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

bool isPrime(int n){
    if (n % 2 == 0) return false;

    bool good = true;
    for (int i = 3; i <= sqrt(n) + 1; i++){
        if (n % i == 0){
            good = false;
            break;
        }
    }
    return good;
}

/*
Painfully generate all the palindromes in a given range and
then check if they are prime.
*/

vector<int> out;
void gen(int a, int b){
    if (b <= 10) return;

    int pal;

    for (int i1 = 1; i1 <= 9; i1++){
        pal = 10 * i1 + i1;
        if (isPrime(pal)) out.push_back(pal);
    }


    if (b <= 100) return;
    // skip evens (they aren't prime)
    for (int i1 = 1; i1 <= 9; i1 += 2){
        for (int i2 = 0; i2 <= 9; i2 ++){
            pal = 100 * i1 + 10 * i2 + i1;
            if (isPrime(pal)) out.push_back(pal);

            pal = 1000 * i1 + 100 * i2 + 10 * i2 + i1;
            if (isPrime(pal)) out.push_back(pal);
        }
    }

    if (b <= 10000) return;

    for (int i1 = 1; i1 <= 9; i1 += 2){
        for (int i2 = 0; i2 <= 9; i2 ++){
            for (int i3 = 0; i3 <= 9; i3 ++){
                pal = 10000 * i1 + 1000 * i2 + 100 * i3 + 10 * i2 + i1;
                if (isPrime(pal)) out.push_back(pal);

                pal = 100000 * i1 + 10000 * i2 + 1000 * i3 + 100 * i3 + 10 * i2 + i1;
                if (isPrime(pal)) out.push_back(pal);
            }
        }
    }

    if (b <= 1000000) return;

    for (int i1 = 1; i1 <= 9; i1 += 2){
        for (int i2 = 0; i2 <= 9; i2 ++){
            for (int i3 = 0; i3 <= 9; i3 ++){
                for (int i4 = 0; i4 <= 9; i4 ++){
                    pal = 1000000 * i1 + 100000 * i2 + 10000 * i3 + 1000 * i4 + 100 * i3 + 10 * i2 + i1;
                    if (isPrime(pal)) out.push_back(pal);

                     pal = 10000000 * i1 + 1000000 * i2 + 100000 * i3 + 10000 * i4 + 1000 * i4 + 100 * i3 + 10 * i2 + i1;
                     if (isPrime(pal)) out.push_back(pal);
                }
            }
        }
    }
}

int main() {

	ifstream fin("pprime.in");
	ofstream fout("pprime.out");

	int a, b;
	fin >> a >> b;

	gen(a, b);
    if (a == 5) fout << 5 << endl;
    if (a <= 7 && b >= 7) fout << 7 << endl;
    sort(out.begin(), out.end());
    for (int i = 0; i < out.size(); i++){
        if (out[i] > b) break;
        else if (out[i] <= b && out[i] >= a) fout << out[i] << endl;
    }


    return 0;

}
