/*
ID: alec3
LANG: C++14
PROG:
*/
/*

*/


#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" " << endl;
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

const ll MOD = 1e9 + 7;
const ll INF = 1e10 + 70;
const ll MX = 2 * 1e6;

void solve(int n){
    vector<int> a(n);
    for (auto& it : a) cin >> it;

    int even = 0, odd = 0;
    for (int i = 0; i < n; i++){
        if (a[i] % 2 == 0)
            even ++;
        else
            odd ++;
    }

    if (even == odd || odd + 1 == even){
        cout << n << endl;
    }
    else if (n == 2){
        if (odd == 1 && even == 1)
            cout << 2 << endl;
        else {
            cout << 1 << endl;
        }
    }
    else if (n == 3){
        if (odd == 2){
            cout << 1 << endl;
        }
        else if (odd == 1){
            cout << 3 << endl;
        }
        else if (odd == 3){
            cout << 2 << endl;
        }
    }
    else if (n == 4){
        if (odd == 4){
            cout << 1 << endl;
        }
        else {
            int ans = 0;

            while (odd > even){
                odd -= 2;
                even ++;
            }
            if (even - odd == 1){
                    ans = max(odd + even, ans);
                }
            else if (even == odd){
                cout << even + odd << endl;
            }
            else {
                ans = max(2 * min(odd, even) + 1, ans);
            }
            cout << ans << endl;
        }
    }

    else {
        //cout << odd << "  " << even << endl;
        int ans = 0;

        while (odd > even){
            odd -= 2;
            even ++;
        }
        assert(odd <= even);
        assert(odd >= 0);

        if (even - odd == 1){
                ans = max(odd + even, ans);
            }
        else if (even == odd){
            ans = even + odd;;
        }
        else {
            ans = max(2 * odd + 1, ans);
        }
        cout << ans << endl;

    }
}


int main()
{
    int n;
    cin >> n;
    solve(n);



    return 0;
}
