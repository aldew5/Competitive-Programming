/*
Aldew
PROB: Chefs in Queue
CLASSIFICATION: Implementation, stacks
DIFFICULTY:
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <map>
#include <math.h>
#include <cstdio>
#include <stack>


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, k;
    cin >> n >> k;

    ll arr[n];
    ll it;
    for (int i = 0; i < n; i++){
        cin >> it;
        arr[i] = it;
    }

    ll ans = 1;
    // value, index
    stack<pair<int, int>> st;

    // the stack stores chefs that still need to be paired up

    for (int i = 0; i < n; i++){
        // when the stack is empty every previous chef has been paired

        // when these conditions are true it means that the chef can delegate
        // a[i]
        while (!st.empty() && st.top().first > arr[i]){
            pair<int, int> element = st.top();
            int chaos = i - element.second + 1;
            ans *= chaos;
            ans %= MOD;
            st.pop();

        }
        // the stack is in order from greatest to least
        // because for a[i] to be added on the stack it must be
        // greater than st.top()
        // otherwise st.top() would have been paired and popped
        st.push(make_pair(arr[i], i));
    }
    cout << ans << endl;

    return 0;
}





