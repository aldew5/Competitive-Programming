// Aldew



#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>


#define line cout << "--------------------" << endl;
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define vll vector<ll>
#define vi vector<int>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

const ll INF = 1e10 + 70;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;


bool s(pair<int,int> one, pair<int, int> two) {
    return one.ss < two.ss;
};

int main() {
 
    int T;
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
    
        map<int, bool> p_used, q_used;
        vector<pair<int, int>> p, q;
        bool good = true;
        
        for (int i = 0; i < n; i++){
            if (p_used[a[i]] && q_used[a[i]]) {
                good = false;
                break;
            }
            
            if (!q_used[a[i]]) {
                q.pb({a[i], i});
                q_used[a[i]] = true;
                
                p.pb({-1, i});
            } else {
                p.pb({a[i], i});
                p_used[a[i]] = true;
                
                
                q.pb({-1, i});
            }
            
        }
        
        if (!good){
            cout << "NO" << endl;
        } else {
            vi b, c;
            for (int i = 1; i <= n; i ++){
                if (!p_used[i]) {
                    b.pb(i);
                }
                
                if (!q_used[i]){
                    c.pb(i);
                }
            }
            
            sort(q.rbegin(), q.rend());
        
            
            int index = int(b.size() -1);
            for (int i = 0; i < n; i++){
                if (p[q[i].ss].ff == -1){
                    p[q[i].ss].ff = b[index];
                    
                    index --;
                }
            }
            sort(q.begin(), q.end(), s);
            
            
            sort(p.rbegin(), p.rend());
            index = int(c.size() ) -1;
            for (int i = 0; i < n; i++){
                if (q[p[i].ss].ff == -1){
            
                    q[p[i].ss].ff = c[index];
                    index --;
                }
            }
            sort(p.begin(), p.end(), s);
            
            if (good){
                for (int i = 0; i < n; i++){
                    if (max(p[i].ff, q[i].ff) != a[i]){
                        good = false;
                        break;
                    }
                }
                if (good){
                    cout << "YES" << endl;
                    for (int i = 0 ;i < n; i++){
                        cout << p[i].ff << " ";
                    }
                    cout << endl;
                    for (int i = 0 ;i < n; i++){
                        cout << q[i].ff << " ";
                    }
                    cout << endl;
                } else {
                    cout << "NO" << endl;
                }
                
                
            } else {
                cout << "NO" << endl;
            }

        }
        
    }
 
    return 0;
 }
