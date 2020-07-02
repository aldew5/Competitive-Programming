/*
ID: alec3
LANG: C++14
PROG: milk2
CLASSIFICATION: brute force
*/

#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;


using namespace std;

/*
Go through all the times between the start and end and
mark them as either idle or working. Go through the list
again and count the greatest interval for each. O(N).
*/

int main(){

    ofstream fout("milk2.out");
    ifstream fin("milk2.in");

    int n;
    fin >> n;
    int ma = 0, mi = INT_MAX;

    bool used[1000000];
    for (int i = 0; i < 1000000; i++){
        used[i] = false;
    }

    int start, finish;
    while (n --){
        fin >> start >> finish;

        for (int i = start; i < finish; i++){
            used[i] = true;
        }
        ma = max(ma, finish);
        mi = min(mi, start);
    }

    int out = 0, c = 0, c2 = 0, idle = 0;
    for (int i = mi; i <= ma; i++){
        if (used[i] == false) {
            out = max(out, c2);
            c2 = 0;
            c ++;
        }
        else {
            idle = max(idle, c);
            c = 0;
            c2 ++;
        }
    }
    fout << out << " " << idle << endl;


    return 0;
}
