/*
Aldew
PROB: Multiple of Three
CLASSIFICATION: Math
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
#include <stack>2


typedef long long ll;

using namespace std;

int prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

string infixToPostfix(string s)
{
    std::stack<char> st;
    st.push('N');
    int l = s.length();
    string ns;
    for(int i = 0; i < l; i++) {
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
        ns+=s[i];

        else if(s[i] == '(') st.push('(');

        else if(s[i] == ')') {
            while(st.top() != 'N' && st.top() != '('){
                char c = st.top();
                st.pop();
               ns += c;
            }
            if(st.top() == '(') {
                char c = st.top();
                st.pop();
            }
        }

        else{
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top())) {
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(s[i]);
        }

    }
    while(st.top() != 'N') {
        char c = st.top();
        st.pop();
        ns += c;
    }

    return ns;

}

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;

        string in;
        cin >> in;

        stack<char> st;
        string ans = infixToPostfix(in);

        cout << ans << endl;

    }



    return 0;
}





