/*
Aldew
CLASSIFICATION: Greedy
*/

#include <iostream>
#include <vector>

using namespace std;

/*
Splitting up a number is the same as keeping it together.
Therefore there are only three cases.
*/
int solve(int m, int n){

    if (n == 1){
        return 0;
    }
    else if (n == 2){
        return m;
    }
    else{
        return m * 2;
    }

}

int main()
{
    int t;
    vector<int> ans;
    cin >> t;

    for (int i = 0; i < t; i++){
        int m;
        int n;
        cin >> n >> m;

        ans.push_back(solve(m, n));

    }
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

    return 0;
}
