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




int main()
{
    int n, q;
    cin >> n >> q;
    string s; cin >> s;
    string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<char, bool> mp;
    map<char, int> pos;

    vector<int> pre = {0};
    vector<int> prerev = {0};
    for (int i = 0; i < alph.size(); i++)
        pos[alph[i]] = i;

    int ans = 0;
    // left side
    //char dark = 'A'
    for (int j= 0; j < n; j++){

        for (int k = pos[s[j]] + 1; k < alph.size(); k++){
                if (alph[k] == s[j])
                    break;
                mp[alph[k]] = false;
        }


        //cout << "J " << j << endl;
        // don't have a continuous stroke
        if (!mp[s[j]]){
            ans ++;
            //cout << "HERE " << s[j] << endl;
            mp[s[j]] = true;
        }
        pre.pb(ans);
        //cout << ans << endl;
    }
    //cout << "END" << endl;
    for (auto j : alph)
        mp[j] = false;
    ans = 0;
    for (int j = n -1; j > 0; j--){
        for (int k = pos[s[j]] + 1; k < alph.size(); k++){
                if (alph[k] == s[j])
                    break;
                mp[alph[k]] = false;
        }


        //cout << "J " << j << endl;
        // don't have a continuous stroke
        if (!mp[s[j]]){
            ans ++;
            //cout << "HERE " << s[j] << endl;
            mp[s[j]] = true;
        }
        prerev.pb(ans);
        //cout << ans << endl;
    }


    int a,b;
    for (int i =0; i < q; i++){
        cin >> a >> b;
        a--;
        //cout << "HERE " << pre[a] << " " << prerev[n-b] << endl;
        cout << pre[a] + prerev[n-b]<< endl;
    }

    return 0;
}
