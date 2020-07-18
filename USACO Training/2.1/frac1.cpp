/*
ID: alec3
LANG: C++14
PROG: frac1
CLASSIFICATION: brute force
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;
set<string> vals;
void gen(int n){

    string s;
    // denom
    for (int i = 2; i <= n; i++){
        // num
        for (int j = 1; j < i; j++){
            // check for same divisor
            bool good = true;
            s = "";
            for (int k = 2; k <= min(i, j); k++){
                if (i % k == 0 && j % k == 0){
                    good = false;
                    break;
                }
            }
            s = to_string(j) + "/" + to_string(i);
            if (good) vals.insert(s);
        }
    }
}

long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {

        if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base);
        }
        base = (base * base);
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
}

int main()
{
    ifstream fin("frac1.in");
	ofstream fout("frac1.out");

    int n;
    fin >> n;

    gen(n);
    vals.insert("1/1");
    vals.insert("0/1");

    vector<pair<double, string>> ans;
    double a, b;
    for (auto i : vals){
        a = (double)(i[0] - '0');

        if (i.size() == 1){
            b = (double)(i[2] - '0');
        }
        else {
            //cout << "I " << i.size() << i << endl;
            for (int j = 2; j < i.size(); j++){
                b += (i[j] - '0') * fast_power(10, (i.size() -2) - j);
            }
        }

        double val = a/b;
        ans.push_back({val, i});
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].ss << endl;
        fout << ans[i].ss << endl;
    }


    return 0;

}
