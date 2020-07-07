/*
ID: alec3
LANG: C++14
PROG: barn1
CLASSIFICATION: brute force
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ifstream fin ("barn1.in");
ofstream fout ("barn1.out");

int main() {

    int m, s, c;
    fin >> m >> s >> c;

    vector <int> stall(c);
    vector<int> gap;
    for (auto & it : stall) fin >> it;

    sort(stall.begin(), stall.end());


    int temp = stall[0];
    // iterate over the stalls
    for(int i = 1; i < stall.size(); i++){
        // if they aren't beside each other
        if(stall[i] - temp > 1){
            // save the distance between them
            gap.push_back(stall[i] - temp - 1);
        }
        temp = stall[i];
    }
    // sort distances
    sort(gap.begin(), gap.end());


    int gapNum = m - 1;

    // more boards than needed
    if(gapNum > gap.size()) gapNum = gap.size();

    // remove the m - 1 smallest gaps
    for(int i = 0; i < gapNum; i++){
        gap.erase(gap.end()-1);
    }

    // add the remaining largest gaps
    for(int i = 0; i < gap.size(); i++){
        c += gap[i];
    }

    fout << c << endl;
    cout << c << endl;
    return 0;
}
