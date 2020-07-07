/*
ID: alec3
LANG: C++14
PROG: crypt1
CLASSIFICATION: brute force
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;

using namespace std;


set<int> nums;
bool isGood(int x, int digit){
    string str = to_string(x);

    // make sure the multiplicand is the right size
    if (str.size() != digit){
        return false;
    }

    // check if each element is allowed
    for (int i = 0; i < str.size(); i++){
        set<int>::iterator it = nums.find(str[i] - '0');
        if (it == nums.end()) return false;
    }
    return true;
}

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");

    int n;
    fin >> n;

    int num;
    for (int i = 0; i < n; i++){
        fin >> num;
        nums.insert(num);
    }

    int ans = 0;
    for (int i = 100; i < 1000; i++){
        for (int j = 10; j < 100; j ++){
            if (isGood(i, 3) && isGood(j, 2) && isGood(i * (j % 10), 3) && isGood(i * (j/10), 3)
            && isGood(i * j, 4)){
                ans ++;
            }

        }
    }
    cout << ans << endl;
    fout << ans << endl;






	return 0;
}

