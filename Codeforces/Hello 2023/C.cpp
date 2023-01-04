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


int main() {
 
    int T;
    cin >> T;
    while (T --) {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        vector<ll> pre;
        ll sum = 0;
        for (int i = 0; i < n; i++){
            sum += a[i];
            pre.pb(sum);
        }
    
        
        priority_queue<ll> p;
        ll ans = 0;
        
        ll val = pre[m-1];
        for (int i = m-2; i > -1; i--){
            if (a[i+1] > 0){
                p.push(a[i+1]);
            }
            
            if (pre[i] < pre[m-1]) {
                while (pre[i] < val) {
                    val -= 2 * p.top();
                    ans ++;
                    p.pop();
                    
                }
            }
        }
        
        
        // min
        priority_queue<ll> p2;
        for (int i = m; i < n; i ++){
            if (a[i] < 0) {
                p2.push(-1 *a[i]);
            }
           
            if (pre[i] < pre[m-1]) {
                while (pre[i]< pre[m-1]){
                    ll mn = p2.top() * -1;
                    pre[m-1] += 2 * mn;
                    ans ++;
                    p2.pop();
                }
                
            }
        }
        cout << ans << endl;
            
    }
    
    
    return 0;
 }
