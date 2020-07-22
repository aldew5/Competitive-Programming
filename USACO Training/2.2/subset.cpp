/*
ID: alec3
LANG: C++14
PROG: subset
CLASSIFICATION:
credit to Nick Tomitov
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ifstream fin ("subset.in");
ofstream fout ("subset.out");

const int MAX = 1024;
// dp array
ll dp[MAX];


int main() {
    io;
    int n;
    fin >> n;

    // sum of the seres
    int s = n * (n + 1)/2;
    // if the sum is not divisible by two
    // there doesn't exist a valid answer
    if (s % 2){
        fout << 0 << endl;
        return 0;
    }
    // divide the sum by two to get the sum
    // we want to calculate
    s /= 2;
    // we can always make 0 one way (empty set)
    dp[0] = 1;

    // loop through the values in the set
    for (int i = 1; i <= n; i++){
        // loop through possible valid sums
        for (int j = s; j >= i; j--){
            // we can make j the same number of times
            // we can make j - i
            dp[j] += dp[j-i];
        }
    }
    // how many ways we can make the required sum
    // (divide by two because we're double counting each ordering)
    fout << (dp[s]/2) << endl;
    return 0;
}
