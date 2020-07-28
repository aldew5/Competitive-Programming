/*
ID: alec3
LANG: C++14
PROG: zerosum
*/


#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define FOR(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
int n;
vector<string> ans;
void solve(string pre, char operation, int val, int num){
    //cout << "NUM " << num << endl;
    if (operation == '+') val += num;
    else if (operation == '-') val -= num;
    else {
        int index = pre.size() -1;
        string s = "";
        while (index >= 0){
            if (pre[index] != '+' && pre[index] != '-' && pre[index] != ' '){
                s += pre[index];
            }
            else if (pre[index] != ' ') break;
            index --;
        }
        reverse(s.begin(), s.end());
        string sub = s.substr(0, s.size() - 1);
        //cout << "sub is " << sub << endl;
        //cout << sub << endl;
        if (index == -1) val = (stoi(s) * 10 + num);
        else if (pre[index] == '+'){
            //cout << '1' << endl;
            //cout << "sub " << sub << endl;
            if (sub != ""){
                val -= stoi(sub);
            }
            else{
                val -= stoi(s);
            }
            val += (stoi(s) * 10 + num);
        }
        else {
            //cout << '2' << endl;
            //cout << "sub " << sub << endl;
            if (sub.size() > 0)
                val += stoi(sub);
            else
                val += stoi(s);
            val -= (stoi(s) * 10 + num);
        }
        //cout <<"val is now " << val << endl;
    }
    if (num == n){
        if (val == 0)
            ans.pb(pre + operation + to_string(num));
        return;
    }

    solve(pre + operation + to_string(num), ' ', val, num + 1);
    solve(pre + operation + to_string(num), '+', val, num + 1);
    solve(pre + operation + to_string(num), '-', val, num + 1);
}


vector<int> dp[10];

int main() {
    fin >> n;

    solve("1", '+', 1, 2);
    solve("1", '-', 1, 2);
    solve("1", ' ', 1, 2);

    sort(ans.begin(), ans.end());
    FOR(i, 0, ans.size()){
        fout << ans[i] << endl;
    }


    return 0;

}
