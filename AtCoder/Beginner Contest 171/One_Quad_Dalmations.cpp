/*
ID: alec3
LANG: C++14
PROG:
*/
/*
Figure out what range the string is (the length of the string). Then
treat every character as its own. Take n mod 26 and find the char's position
in the 1 -> 26 range then divide n by 26 to look at the next letter. In this way
we can just classify every letter individually.
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


int main()
{
    io;
    ll n;
    cin >> n;
    // current set of names and their length
    ll curr = 26;
    int len = 1;

    // find the range of strings
    // n is in and their length
    while (n > curr){
        n -= curr;
        curr *= 26;
        len ++;
    }
    // ans is a string full of 0 of length len
    string ans(len, '0');
    n --;

    // start at the end of the string
    for (int i = len-1; i >= 0; i--){
        // the letter is the number of nums after 26 (pos in alphabet)
        // + 'a' to make it a proper char
        ans[i] = n % 26 + 'a';
        // look at the eariler set of numbers
        n /= 26;
    }
    cout << ans << endl;

    return 0;
}
