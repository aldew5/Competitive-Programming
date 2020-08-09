/*
ID: alec3
LANG: C++14
PROG:
*/
/*
We start by counting the number of elements we have. We then do
binary search to find the maximum possible difference bewteen
equal integers.

To check if it works we first start with a set containing the element
and its frequency sorting by frequency (greatest to least). We then choose
the element with the greatest frequency greedily and remove it from the set
until its needed again (x moves later). We continue to build this vector until
b until the set is empty or we have used all the numbers. If we have used all the elements
it was a valid x, otherwise the space was too big.
*/


#include <bits/stdc++.h>

//#define check(x) cout<<(#x)<<": "<<x<<" ";
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


const int MAXN = 100009;
int cnt[MAXN];
vector<int> a;
int n;

bool check(int x){

    // reset counts
    for (int i = 1; i <= n; i++)
        cnt[i] = 0;
    // update with current vals
    for (int i = 0; i < n; i++)
        cnt[a[i]] ++;

    // use the greater comparator to sort the set in descending order
    // we're storing count and element
    set<pair<int,int>, greater<pair<int, int>>> s;

    // if we have the element available put it in s
    for (int i = 1; i <= n; i ++){
        if (cnt[i] > 0) s.insert({cnt[i], i});
    }
    vector<int> b;
    // loop through values
    for (int i = 0; i < n; i++){
        // b is empty in the first iteration
        // if value not negative and we have more than 0 of this element

        // this occurs when its time for an element to repeat
        // (it gets added back on to the set)
        if (i >= x && cnt[b[i-x]] > 0){
            s.insert({cnt[b[i - x]], b[i - x]});
        }

        // x was too big
        if (s.empty())
            return 0;

        // append the most frequent element
        b.pb(s.begin() -> second);

        // erase the element we just used
        s.erase(s.begin());
        // used up the newest element added to b
        cnt[b.back()] --;
    }
    return 1;
}

int main()
{
    io;
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        a.resize(n);
        // read input
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        // binary search for the answer
        // we can do this because if m is possible so
        // are all the distances before m
        int l = 0, r = n;
        while (r - l > 1){
            int m = (r + l) /2;
            if (check(m))
                l = m;
            else
                r = m;

            //cout << "HERE" << endl;
        }
        cout << l - 1 << endl;
    }


    return 0;
}

