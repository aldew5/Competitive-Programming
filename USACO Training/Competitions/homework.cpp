/*
ID: alec3
LANG: C++14
PROG:
*/
/*
0, 0, 0, 0, 0
0, 1, 1, 1, 0 -> 0, 1, 0, 0, -1

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

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}


using namespace std;

const int MXN = 100000;

ll score[MXN + 1];
ll suffix_sum[MXN + 1];
ll suffix_min[MXN + 1];
ll best_num, best_den;

int main()
{
    setIO("homework");

    int n;
    cin >> n;

    for (int i =1; i <=n; i++)
        cin >> score[i];
    
    // we're starting from the end of the list
    // update the suffix sum and the min sum (just the only number available)
    suffix_sum[n] = score[n];
    suffix_min[n] = score[n];
    
    // loop through the list of scores starting from the end
    for (int i = n-1; i >= 1; i--){
        // the suffix sum is the sum up to that point plus the new point
        suffix_sum[i] = suffix_sum[i+1] + score[i];
        // the min value is the min of the new value and the smallest value up until that point
        suffix_min[i] = min(suffix_min[i+1], score[i]);
    }
    
    // store the values of the greatest value and the corresponding k
    best_num = 0; best_den = 1;

    for (int i = 1; i < n-1; i++){
        // the calculated value (we multiply by the current k) > the max value (multiply by current i)
        // curr / (n-(i+1)) = best / k
        // curr * k = best * (n-(i + 1))
                                                                                
        if ((suffix_sum[i+1]-suffix_min[i+1]) * best_den > best_num * (n-(i+1))){
            best_num = suffix_sum[i+1] - suffix_min[i+1];
            best_den = n-(i + 1);
        }
    }
    // print out the value of i that has the max value THAT'S WHY MY LAST SOLUTION FAILED FUCK
    for (int i = 1; i < n-1; i++){
        if ((suffix_sum[i+1] - suffix_min[i+1]) * best_den == best_num *(n-(i +1)))
            cout << i << endl;
    }

    return 0;
}
