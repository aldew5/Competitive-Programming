/*
ID: alec3
LANG: C++14
PROG:
*/
/*
We can simply the problem by stating that we want to count the 
number of equal pairs where i < j < k < l. We loop over j from right
to left to find all (a[k], a[l]) pairs that meet the criterion and store
them in frequency.

We then loop through all the possible i's and increment total by the ones
that have the same vaule. We solve it with brute force.
*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ld long double
#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

//ifstream fin("maze1.in");
//ofstream fout("maze1.out");
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);

    for (auto &it : a) {
        cin >> it;
        // subtract 1 so 0 <= a[i] < n
        it --;
    }

    vector<int> freq(n * n, 0);
    ll total = 0;
    
    // loop through the list starting at the last element
    for (int j = n -1; j >= 0; j --){
        // k is the previous j
        int k = j + 1;
    
        // l is everything after k
        for (int l = k + 1; l < n; l ++){
            // becuase a and b are both numbers in [0, n) then an + b
            // maps each pair to a unique number. This way we don't 
            // need to store the actual pairs
            freq[a[k] * n + a[l]] ++;
        }
        // loop through the numbers on the other side
        // compress them and increment the total by the 
        // amount of pairs we already have with this same value
        for (int i = 0; i < j; i++)
            total += freq[a[i] * n + a[j]];
    }
    cout << total << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}
