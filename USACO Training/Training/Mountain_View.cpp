/*
ID: alec3
LANG: C++14
PROG:
*/
/*
For the peaks to coincide the base of the previous mountain
must completely ecompass the next mountain's base.

Since the slope is 1 we have an interval for the base:
[x-y, x + y]

We make a custom comparator and sort the mountings in increasing 
order by x_i - y_i.  We then loop through and check if there is 
a mountain j such that the in
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
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

ifstream fin("mountains.in");
ofstream fout("mountains.out");

const int MAXN = 100000;
int n;
int x[MAXN], y[MAXN];
int pos[MAXN], neg[MAXN];
int cid[MAXN];

bool cmp(int a, int b){
    if (neg[a] == neg[b])
        return pos[a] > pos[b];
    return neg[a] < neg[b];
}


int main()
{
    io;
    fin >> n;
    
    // read input
    for(int i = 0; i < n; i++){
        fin >> x[i] >> y[i];
        // save the position of the right point and the position
        // of the left point in the pos and neg arrays respectively
        pos[i] = x[i] + y[i], neg[i] = x[i] - y[i];
        // save the mountain's id
        cid[i] = i;
    }
    
    // sort the ids of the mountains based on the sorting 
    // criteria outlined in the explanation above.
    sort(cid, cid + n, cmp);

    int mxpos = -1, ans = 0;
    // loop through mountains (in order)
    for (int i = 0; i < n; i++){
        // the positive value (right point) is greater than the previous
        // furthest right point.  This means that the mountain
        // isn't occluded
        if (pos[cid[i]] > mxpos){
            // update answer and the mxposition on the right
            ans ++;
            mxpos = pos[cid[i]];
        }
    }
    fout << ans << endl;


    return 0;
}
