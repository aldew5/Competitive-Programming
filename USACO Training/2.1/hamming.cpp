/*
ID: alec3
LANG: C++14
PROG: hamming
CLASSIFICATION:
credit to Brain Jacokes
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ifstream fin ("hamming.in");
ofstream fout ("hamming.out");

const int MAX = (1 << 8 + 1);
// we can find the value of the nth bit of a number M
// with the expression (1 << N) & M
// shifting 1 N bits results in a binary string in the form
// 00...1000..00 where there is a 1 in the Nth place and a 0 everywhere else
// if the result is a one then there must be a one at the Nth bit of M as
// well

const int NMAX = 65;
const int BMAX = 10;
const int DMAX = 10;

int nums[NMAX];
int dist[MAX][MAX];
int n, b, d, maxval;


void gen(int cur, int start){
    int a, b, canuse;
    char ch;

    // reached the number of vals we need to print
    if (cur == n){
        // print nums
        for (a = 0; a < n; a++){
            fout << nums[a];
            if (a + 1 != n && (a+1) % 10 != 0) fout << " ";

            if ((a+1) % 10 == 0 && a + 1 != n) fout << endl;
        }
        fout << endl;
        // end the program
        exit(0);
    }
    // loop through possible as
    for (a = start; a < maxval; a++){
        canuse = 1;
        // loop through the nums we have
        for (b = 0; b < cur; b++){
            // invalid distance
            if (dist[nums[b]][a] < d){
                // can't use
                canuse = 0;
                break;
            }
        }
        if (canuse){
            // add number to our list
            nums[cur] = a;
            // look for more
            gen(cur+1, a+1);
        }
    }
}

int main() {
    io;
    fin >> n >> b >> d;
    maxval = (1 << b);
    // loop through vals
    for (int i = 0; i < maxval; i++){
        for (int j = 0; j < maxval; j++){
            // set distance to none
            dist[i][j] = 0;
            // loop through bits in k
            for (int k = 0; k < b; k++){
                // check if the kth bit of k is different
                // from the kth bit of j
                if (((1 << k) & i) != ((1 << k) & j))
                    // if it's different, then the Hamming distance should
                    // be one greater
                    dist[i][j] ++;
            }
        }
    }
    // zero is always possible
    nums[0] = 0;
    gen(1, 1);
    
    return 0;
}
