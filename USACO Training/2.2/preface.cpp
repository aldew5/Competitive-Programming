/*
ID: alec3
LANG: C++14
PROG: preface
CLASSIFICATION:
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ifstream fin ("preface.in");
ofstream fout ("preface.out");

map<char, int> m;
set<char> vals;
void addRoman(int number)
{
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i=12;
    while(number>0)
    {
      int div = number/num[i];
      number = number%num[i];
      while(div--)
      {
        for (int j = 0; j < sym[i].size(); j++){
            m[sym[i][j]] ++;
            vals.insert(sym[i][j]);
        }

      }
      i--;
    }
}

int main() {
    io;
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++){
        addRoman(i);
    }

    string lets = "IVXLCDM";
    for (int i = 0; i < lets.size(); i++){
        if (vals.find(lets[i]) != vals.end()){
            fout << lets[i] << " " << m[lets[i]] << endl;
        }
    }
    return 0;
}
