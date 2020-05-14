/*
ID: alec3
LANG: C++14
PROG: friday
CLASSIFICATION: Ad Hoc
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

int getMonthLength(int month_index, int year){
    if (month_index == 8 || month_index == 3 || month_index == 5 || month_index == 10){
        return 30;
    }
    else if (month_index == 1){
        // leap year
        if (((year % 100 == 0) && (year % 400 == 0)) || ((year % 100 != 0) && (year % 4 == 0))){
            return 29;
        }
        else {
            return 28;
        }
    }
    else {
        return 31;
    }
}

int main()
{
    map<int, int> values;

    // create the map values
    for (int i = 0; i < 7; i ++){
        values[i] = 0;
    }

    ofstream fout("friday.out");
    ifstream fin("friday.in");

    int n;
    fin >> n;

    int year = 1900;
    int last = year + n;
    int day_index = 0;

    // go through all the years
    while (year < last){
        // go through all the months
        for (int i = 0; i < 12; i++){
            values[(day_index + 5) %7] += 1;

            //go to next month
            day_index += (getMonthLength(i, year) %7);
            day_index %= 7;
        }
        year ++;
    }
    // Sat and Sun
    fout << values[5] << " " << values[6] << " " << values[0]
    << " " << values[1] << " " << values[2] << " " << values[3]
    << " " << values[4] <<endl;
    return 0;
}
