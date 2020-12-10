/*
ID: alec3
LANG: C++14
PROG:
*/
/*
We start from the leftmost cow. For each new cow, if we find it's first choice has been
picked already we switch out the cow who took it. We propagate this switch down the line of cows
until we have a valid solution.
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
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}


using namespace std;

int n, m;
int f[100001], s[100001], occ[100001];

int ans[100001];

int main()
{
    setIO("cereal");
    cin >> n >> m;
    // read in first and second preferences
    F0R(i, n){
        cin >> f[i] >> s[i];
    }

    int cnt = 0;
    // start from the last cow
    for (int i = n-1; i >= 0; i--){
        // set j to the cow number and pos to the cow's first choice
        int j = i, pos = f[i];
        while(true){
            // if the cow's first choice is avialable
            if (!occ[pos]){
                // set it to occupied by the cow
                occ[pos] = j;
                // update the answer
                cnt ++;
                break;
            }
            // an earlier cow is occupying the pos break
            else if (occ[pos] < j)
                break;
            else {
                // set c to the cow at pos
                int k = occ[pos];
                // put the new in the position
                occ[pos] = j;
                // if the first choice of the current cow is the second choice
                // of a further right cow than we're maintaining the solution
                // just break out
                if (pos == s[k])
                    break;
                // otherwise set j to the position of the cow occupying the newest cow's
                // first choice and update the position we're trying to fill
                // as the cows second choice
                j = k; pos = s[k];
            }
        }
        ans[i] = cnt;
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;

    return 0;
}
