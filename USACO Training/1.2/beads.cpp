/*
ID: alec3
LANG: C++14
PROG: beads
CLASSIFICATION: Ad Hoc
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

/*
Break it between the strings of greatest length
*/

int main()
{
    ofstream fout("beads.out");
    ifstream fin("beads.in");

    int n;
    string beads;
    // create a vector of vectors
    vector<vector<int>> groupings;
    int most = 0;
    char previous_color = 'm';

    fin >> n >> beads;

    // generate a list of grouped beads
    for (int i =0; i < n; i++){
        char current_color = beads[i];

        // still on same color
        if (current_color == previous_color){
            groupings.back()[1] = i;
        }
        // don't do anything for white
        else if (current_color == 'w'){
            continue;
        }
        // new color
        else{
            // add a position vector
            groupings.push_back({i,i});
            previous_color = current_color;
        }

    }
    // static cast it to an int so it can have negative values
    int groupings_size = static_cast<int>(groupings.size());

    // all beads are included
    if (groupings_size <= 2){
        fout << n << "\n";
        return 0;
    }

    // not considering arounds
    for (int i = 0; i < groupings_size -1; i++){
        // if i is zero the min is 0, otherwise it's the second
        // index of the previous number in groupings + 1
        int min = (i == 0) ? 0 : (groupings[i - 1][1] + 1);
        int max = (i >= groupings_size - 2) ? groupings_size -1 : groupings[i + 2][0] -1;

        // without 'w'
        int size = max - min + 1;
        if (size > most){
            most = size;
        }
    }

    // do consider arounds
    // ends aren't the same color
    if ((groupings_size % 2) == 0){
        // first element of second item + the total length - second index of the second last item
        // in groupings - 1 for 0 index
        int size = groupings[1][0] + n - groupings[groupings_size - 2][1] -1;

        if (size > most){
            most = size;
        }
    }
    else {
        int size = groupings[2][0] + n - groupings[groupings_size - 2][1] -1;

        if (size > most){
            most = size;
        }
        // everythings minus what's not included
        size = groupings[1][0] + n - groupings[groupings_size -3][1] -1;
        if (size > most){
            most = size;
        }
    }

    fout << most << "\n";
    return 0;
}
