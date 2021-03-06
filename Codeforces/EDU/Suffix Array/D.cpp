/*
ID: alec3
LANG: C++14
PROG: ttwo
*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define FOR(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

ifstream fin("ttwo.in");
ofstream fout("ttwo.out");

// sorts array p by the keys stored in array c
void count_sort(vector<int> &p, vector<int> &c){
    int n = p.size();

    vector<int> cnt(n);
    // calculate how many times each element occurs
    for (auto x: c){
        cnt[x] ++;
    }
    vector<int> p_new(n);
    vector<int> pos(n);
    pos[0] = 0;
    // create the buckets
    for (int i = 1; i < n; i++){
        pos[i] = pos[i-1] + cnt[i -1];
    }
    // put elements in buckets
    for (auto x : p){
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i] ++;
    }
    // copy to p_new
    p = p_new;
}


int main()
{
    string s;
    cin >> s;
    s += "$";

    int n = s.size();
    vector<int> p(n), c(n);

    {
        // sort the characters
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++) a[i] = {s[i], i};
        sort(a.begin(), a.end());

        // store the positions array in p
        for (int i = 0; i < n; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        // create equivalance classes
        // so we can compare strings in constant time
        for (int i = 1; i < n; i++){
            if (a[i].first == a[i-1].first){
                c[p[i]] = c[p[i-1]];
            }
            else {
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
    }


    int k = 0;
    // loop through ks (powers of 2 that further sort the longer suffixes)
    while ((1 << k) < n){

        // sort by the second half
        for (int i = 0; i < n; i++){
            p[i] = (p[i] - (1 << k) + n) % n;
        }


        // sort by the fist half to get a fully sorted array
        count_sort(p, c);

        vector<int> c_new(n);
        c_new[p[0]] = 0;
        // create equivalence classes
        c[p[0]] = 0;
        for (int i = 1; i < n; i++){
                // equivalence class of the left and right parts
                pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
                pair<int, int> prev = {c[p[i -1]], c[(p[i -1] + (1 << k)) % n]};
            if (now == prev){
                c_new[p[i]] = c_new[p[i-1]];
            }
            else {
                c_new[p[i]] = c_new[p[i-1]] + 1;
            }
        }
        c = c_new;
        k ++;
    }

    int len;
    cin >> len;
    while (len --){
        string q;
        cin >> q;
        bool good;
        int index;
        // Do binary search on the suffix array
        int low = 0, high = p.size() - 1;
        while (low <= high){
            good = false;
            string sub = s.substr(p[(high + low)/2], q.size());

            if (sub == q){
                good = true;
                index = (high + low) /2;
                break;
            }
            else if (sub > q)
                high = (high + low) /2 -1;
            else
                low = (high + low) /2 + 1;

        }
        if (!good)
            cout << 0 << endl;
        else {
            int l = -1;
            low = 0, high = index -1;
            while (low <= high){
                int mid = (high + low) /2;
                string sub = s.substr(p[mid], q.size());

                if (sub == q){
                    high = mid - 1;
                    if (l == -1)
                        l = mid;
                    else
                        l = min(l, mid);
                }
                else if (sub < q)
                    low = mid + 1;
                else
                    high = mid -1;
            }

            int r= -1;
            low = index + 1, high = p.size() -1;
            while (low <= high){
                int mid = (high + low) /2;
                string sub = s.substr(p[mid], q.size());

                if (sub == q){
                    low = mid +1;
                    r = max(mid, r);
                }
                else if (sub < q)
                    low = mid + 1;
                else
                    high = mid -1;
            }

            //cout << "HERE " << l << " " << r << " " << index << endl;
            if (r != -1 && l != -1)
                cout << r - l + 1 << endl;
            else if (r == -1 && l != -1)
                cout << abs(l - index) + 1 << endl;
            else if (l == -1 && r != -1)
                cout << abs(index - r) + 1 << endl;
            else
                cout << 1 << endl;
        }
    }


    return 0;
}
