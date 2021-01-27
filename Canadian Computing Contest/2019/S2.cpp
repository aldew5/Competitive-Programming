
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

ll N = 2 * 1000000;
vector<char> is_prime(2 * 1000000 + 1, true);
void Sieve(){
    is_prime[0] = is_prime[1] = false;

    for (ll i = 2; i * i<= N; i++){
        if (is_prime[i]){
            for (ll j = i * i; j <= N; j+=i)
                is_prime[j] = false;
        }
    }
    return;
}


int main()
{
    int t;
    cin >> t;
    Sieve();
    while (t--){
        int n;
        cin >> n;
        for (int i = 4; i < 2000000; i++){
            if (!is_prime[i])
                continue;

            if (is_prime[2 * n - i]){
                cout << 2 * n - i << " " << i << endl;
                break;
            }

        }
    }


    return 0;
}

