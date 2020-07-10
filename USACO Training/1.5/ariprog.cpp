/*
ID: alec3
LANG: C++14
PROG: ariprog
CLASSIFICATION: brute force
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll ans  = 0;
int n, m;
vector<pair<int, int>> p;

int length = 0;
bool squares[250 * 250 * 2 + 1] = {false};
void dfs(int length, int current, int incre){

    if (length == n) {
        ans ++;
        p.push_back({incre, current - ((n -1) * incre)});
        return;
    }

    else {
        if (current + incre <= 2 *m*m && squares[current + incre]){
            dfs(length + 1, current + incre, incre);
        }
        else return;
    }



}

int main(void)
{
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");

    fin >> n >> m;

    for (int p = 0; p <= m; p++){
        for (int q = 0; q <= m; q++){
            squares[p *p + q*q] = true;
        }
    }

    // call dfs with each starting value
    for (int i = 0; i <= (2 * m* m); i++){
        if (squares[i]){
            // increment values
            for (int j = 1; i + j * (n-1) <= (2 * m * m); j++){
                dfs(1, i, j);
            }
        }
    }



    sort(p.begin(), p.end());
    if (ans == 0) fout << "NONE" << endl;
    if (ans != 0){
        for (int i = 0; i < p.size(); i++){
            fout << p[i].second << " " << p[i].first << endl;
        }
    }

    return 0;
}
