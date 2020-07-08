/*
ID: alec3
LANG: C++14
PROG: skidesign
CLASSIFICATION: brute force
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;

using namespace std;


// count all solutions
int solve(void)
{

}

int main(void)
{
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");

    int n;
    fin >>n;

    int elevations[n];
    for (int i = 0; i < n; i++) fin >> elevations[i];

    //brute force search to check all possible ranges
    int j = 17;
    int cost = 0, ans = INT_MAX;
    for (int i = 0; i < 100; i++){
        // in proper range
        cost = 0;
        for (int k = 0; k < n; k++){
            if (elevations[k] <= j && elevations[k] >= i) continue;
            else if (elevations[k] < i){
                cost += (i - elevations[k]) * (i - elevations[k]);
            }
            else if (elevations[k] > j){
                cost += (elevations[k] - j) * (elevations[k] - j);
            }
        }
        ans = min(cost, ans);
        j ++;
    }
    fout << ans << endl;

    return 0;
}
