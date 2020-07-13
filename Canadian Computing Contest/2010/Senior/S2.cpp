/*
ID: alec3
LANG: C++14
PROG: Huffman Encoding
CLASSIFICATION: implementation
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


int main()
{
    io;
    int k;
    cin >> k;
    map<string, char> m;

    char let;
    string val;
    while (k --){
        cin >> let >> val;
        m[val] = let;
    }
    string s;
    cin >> s;

    string ans ="";
    string pre = "", empt = " ";
    for (int i = 0; i < s.size(); i++){
        auto it = m.find(pre);

        if (it != m.end()){
            ans += m[pre];
            pre = "";
            pre += s[i];
        }
        else pre += s[i];
    }
    ans += m[pre];
    cout << ans << endl;


    return 0;
}
