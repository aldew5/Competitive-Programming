/*
ID: alec3
LANG: C++14
PROG: milk3
CLASSIFICATION: depth first search
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

//define a state of the milk buckets
struct state{
    int amount[3];
    bool init;
    int steps;
};

int siz[3];
bool visited[21][21][21];

vector<int> ans;
void dfs(int a, int b, int c){
    if (a == 0){
        ans.push_back(c);
    }

    if (visited[a][b][c]) return;
    visited[a][b][c] = true;

    dfs(a + min(c, siz[0] -a), b, c - min(c, siz[0] -a));
    dfs(a - min(siz[2] - c, a), b, c + min(siz[2] - c, a));

    dfs(a + min(b, siz[0] -a), b -min(b, siz[0] -a), c);
    dfs(a - min(siz[1]-b, a), b + min(siz[1] -b, a), c);

    dfs(a, b + min(c, siz[1] - b), c - min(c, siz[1] - b));
    dfs(a, b - min(siz[2] - c, b),c + min(siz[2] - c, b));
}

int main() {

	ifstream fin("milk3.in");
	ofstream fout("milk3.out");

	fin >> siz[0] >> siz[1] >> siz[2];

	int a = 0, b = 0, c = siz[2];

	dfs(a + min(c, siz[0] -a), b, c - min(c, siz[0] -a));
	dfs(a, b + min(c, siz[1] - b), c - min(c, siz[1] - b));

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	for (int i = 0; i < ans.size(); i++){
        if (i == ans.size() -1){
            fout << ans[i];
            cout << ans[i];
        }
        else fout << ans[i] << " ";
	}
    fout << endl;
    return 0;



}
