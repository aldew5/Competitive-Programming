/*
ID: alec3
LANG: C++14
PROG:
*/
/*

*/


#include <bits/stdc++.h>

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

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin); // see /general/io
		freopen((name+".out").c_str(), "w", stdout);
	}
}


int main()
{
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int index = -1;
        int ans = 0;
        int start, last = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '*' && index == -1){
                ans ++;
                s[i] = 'X';
                index = i;
                start = i;
            }
            else if (s[i] == '*'){
                index =i;
            }
        }
        if (s[index] != 'X'){
            s[index] = 'X';
            ans ++;
            last = index;
        }

        int cnt = 0;

        for (int i = start; i < last; i++){
            if (s[i] == 'X'){
                cnt = 0;
            }
            else
                cnt ++;
            if (cnt == k){
                int j = i;
                while (j >= 0){
                    if (s[j] == '*'){
                        s[j] = 'X';
                        ans ++;
                        cnt = i -j;
                        break;
                    }
                    j --;
                }
            }
        }
        //for (int i = last)

        cout << ans << endl;

    }

}
