/*
Aldew
PROB: "Tram"
CLASSIFICATION: Ad hoc, 2D arrays
DIFFICULTY: 800


*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

/*
subtract a then add b
*/
int main()
{
    int num_stops;
    cin >> num_stops;
    int exits[num_stops][2];
    int cap = 0;
    int people = 0;

    for (int i = 0; i < num_stops; ++i){
        int pair[2];
        int a, b;
        cin >> a >> b;
        pair[0] = a;
        pair[1] = b;

        exits[i][0] = a;
        exits[i][1] = b;
    }
    for (int i = 0; i < num_stops; ++i){
        people -= exits[i][0];
        people += exits[i][1];

        if (people > cap) cap = people;
    }
    cout << cap << endl;


    return 0;
}
