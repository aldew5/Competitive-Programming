/*
ID: alec3
LANG: C++14
PROG: cowdance
*/
/*
Binary search for k, the constraints are small enough that
we can simulate the dance each time. Use negative values in 
the priority queue to reverse the order so that the cows
closest to finished dancing are removed first. 
*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" " << endl;
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ld long double
#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define line cout << "--------------" << endl;

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}


int main()
{
    setIO("cowdance");
    int n, t;
    cin >> n >> t;
    int ar[n];

    for (int i = 0; i < n ;i++)
        cin >> ar[i];

    int high = n, low = 1;
    int ans = n;

    while (low <= high){
        int mid = (high + low) /2;
        int time = 0, j= 0;
        priority_queue<int> pq;

        int sz = 0;
        while (sz < mid && j < n){
            pq.push(-ar[j]);
            sz ++;
            j ++;
        }

        while(int(pq.size())){
            time += max(0, -pq.top() - time);
            pq.pop();

            if (j < n){
                pq.push(-(ar[j] + time));
                j ++;
            }
        }

        if (time > t)
            low = mid + 1;
        else{
            ans = min(ans, mid);
            high = mid - 1;
        }
    }
    cout << ans << endl;

    return 0;
}
