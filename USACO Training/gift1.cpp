/*
ID: alec3
LANG: C++14
PROG: gift1
CLASSIFICATION: Ad Hoc
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// define a function to find a friends index in balance
int FindIndex(string person, vector<string> list)
{
    for (int i = 0; i < list.size(); i++){
        if (list[i] == person){
            return i;
        }
    }
    // not in the list
    return -1;
}

int main()
{
    int num_friends;
    vector <string> members;

    ofstream fout("gift1.out");
	ifstream fin("gift1.in");

	fin >> num_friends;
	// declare a vector of length num friends where each
	//friend's balance is 0
	vector<int> balance(num_friends, 0);

    // create a vector of all the names
	for (int i = 0; i < num_friends; i++){
        string member;
        fin >> member;
        members.push_back(member);
	}
	// get data for a person
	for (int i = 0; i < members.size(); i++) {
        string name;
        int total;
        int num_gifts;

        fin >> name >> total >> num_gifts;
        int giver_index;
        giver_index = FindIndex(name, members);

        // not giving zero gifts
        if (!(num_gifts == 0)){
            // take off the remainder because that person keeps it
            total = (total - (total % num_gifts));
            // subtract what they're actually giving (no remainder)
            balance[giver_index] -= total;

            // add to the people that recieved the gift
            for (int i = 0; i < num_gifts; i ++){
                string person;
                fin >> person;

                int person_index = FindIndex(person, members);
                // add the value of the gift
                balance[person_index] += (total / num_gifts);
            }
        }
	}
    //output the names and their balances
    for (int i = 0; i < num_friends; i++){
        fout << members[i] << " " << balance[i] << "\n";
    }
    return 0;
}
