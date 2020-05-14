/*
ID: alec3
LANG: C++14
PROG: ride
CLASSIFICATION: Ad Hoc
*/

#include <iostream>
#include <numeric>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

int main()
{
    string group;
    string comet;

    ofstream fout("ride.out");
	ifstream fin("ride.in");

	fin >> group >> comet;

    //create a char vector called alphabet of size 26
    vector<char> alphabet(26);
    iota(alphabet.begin(), alphabet.end(), 'A');

    map<int, int> m;
    int count = 1;

    for (int i=0; i < 26; i++){
        m[alphabet[i]] = count;
        count ++;
    }
    int gp = 1;
    int cp = 1;

    for (char& c : comet){
        cp *= m[c];
    }
    for (char& c : group) {
        gp *= m[c];
    }

    if (gp % 47 == cp % 47){
        fout << "GO\n";
    }
    else {
        fout << "STAY\n";
    }

    return 0;
}
