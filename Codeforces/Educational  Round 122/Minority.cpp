
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


//#define check(x) cout<<(#x)<<": "<<x<<" " << endl;
#define line cout << "--------------------" << endl;
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

const ll INF = 1e10 + 70;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;

int main () {
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;

        int one = 0;
        int zero = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '1'){
                one ++;
            }
            else {
                zero ++;
            }
        }
        if (s.size() == 2){
            cout << 0 << endl;
        }
        else if (zero != one){
            cout << min(zero, one) << endl;
        }
        else {
            if (s[0] == '0'){
                cout << zero-1 << endl;
            }
            else {
                cout << one-1 << endl;
            }
        }
    }

    return 0;
}
