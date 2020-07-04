/*
ID: alec3
LANG: C++14
PROG: namenum
CLASSIFICATION: brute force
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

/*
Create a map of all the letters mapped to
their corresponding number in chars. Convert
n to a string so it can be iterated over.

Go through all the possible names and check if they 
are valid given based on the map.
*/

int main()
{
    ofstream fout("namenum.out");
    ifstream fin("namenum.in");
    ifstream in("dict.txt");

    vector<string> a;

    // map letter to char of the number
    map<char, char> d;
    string alph = "ABCDEFGHIJKLMNOPRSTUVWXYZ";

    char c = '2';
    int ci;
    int co = 0;

    string p;
    for (int i = 0; i < alph.size(); i++){
        d[alph[i]] = c;
        co ++;


        if (co % 3 == 0) {
            ci = c - '0';
            ci ++;
            string p = to_string(ci);
            c = p[0];
        }
    }

    string line;
    while(getline(in, line)){
        a.push_back(line);
    }

    ll n;
    fin >> n;
    string s = to_string(n);

    vector<string> ans;
    bool good;
    for (int i = 0; i < a.size(); i++){
        if (a[i].size() != s.size()) continue;

        // check if each char corresponds to the correct num
        good = true;
        for (int j = 0; j < a[i].size(); j++){

            if (d[a[i][j]] != s[j]){
                good = false;
                break;
            }
        }
        if (good) ans.push_back(a[i]);
    }

    if (ans.size() > 0){
        for (int i = 0; i < ans.size(); i++){
            cout << ans[i] << endl;
            fout << ans[i] << endl;
        }
    }
    else {
        cout << "NONE"<< endl;
        fout << "NONE" << endl;
    }


 	return 0;
}
