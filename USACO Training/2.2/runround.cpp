/*
ID: alec3
LANG: C++14
PROG: runround
*/

/*
Values are small enough that you can just brute force it.
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ifstream fin ("runround.in");
ofstream fout ("runround.out");


bool uni(string s){
    set<char> vals;
    bool good = true;
    for (int i = 0; i < s.size(); i++){
        if (vals.find(s[i]) != vals.end() || s[i] == '0'){
            good = false;
            break;
        }
        vals.insert(s[i]);
    }
    return good;
}

bool valid(string s){
    if (!uni(s))
        return false;

    set<char> vals;
    int pos = 0;
    while (true){
        if (pos + (s[pos] -'0')< s.size()){
            if (vals.find(s[pos + (s[pos] - '0')]) == vals.end()){
                pos = pos + (s[pos] - '0');
                vals.insert(s[pos]);
            }
            else break;
        }
        else {
            int index = pos;
            for (int i = 0; i < (s[index] - '0'); i++){
                if (pos == s.size() - 1) pos = 0;
                else pos ++;

            }
            if (vals.find(s[pos]) == vals.end()){
                vals.insert(s[pos]);
            }
            else break;
        }

        if (vals.size() == s.size()) break;
    }
    if (vals.size() == s.size()) return true;
    else return false;
}


int main() {
    io;
    int n;
    fin >> n;

    string s;
    for (int i = n + 1; i < n * 10; i++){
        s = to_string(i);
        if (valid(s)) {
            fout << s << endl;
            return 0;
        }

    }

    return 0;
}
