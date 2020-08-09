/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Just keep a count of how many sets of 2 we have and sets of 4
we have. Everytime we change the value remove it from the count
and re-calculate it.
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

using namespace std;

int pct(int x) { return __builtin_popcount(x); }


int const MAXN = 1e5 + 5;
// stores planks of each length
int cnt[MAXN];
int main()
{
    io;
    // count the number of lengths that we have 2 and 4 of
    int n, q, x, cnt2 = 0, cnt4 = 0;
    char type;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> x;
        // remove the count we had for that
        // length up until this point
        cnt2 -= cnt[x] /2;
        cnt4 -= cnt[x] /4;

        // update the legnths
        cnt[x]++;

        // update the counts
        cnt2 += cnt[x] /2;
        cnt4 += cnt[x] /4;
    }
    cin >> q;

    for (int i = 1; i <= q; i++){
        cin >> type >> x;
        // remove the count we had before
        cnt2 -= cnt[x] /2;
        cnt4 -= cnt[x] /4;

        // update the lengths
        if (type == '+')
            cnt[x] ++;
        else
            cnt[x]--;

        // update the count
        cnt2 += cnt[x] /2;
        cnt4 += cnt[x] /4;

        // we have at least one square and one rectangle
        if (cnt4 >= 1 && cnt2 >= 4)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }


    return 0;
}

