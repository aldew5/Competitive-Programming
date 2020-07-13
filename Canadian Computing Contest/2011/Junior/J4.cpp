/*
Aldew
PROB: Boring Business
CLASSIFICATION: Implementation, brute force
DIFFICULTY:
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

bool isSafe (pair<int, int> current, vector<pair<int, int>> pos){
    bool safe = true;
    for (int i = 0; i < pos.size(); i++){
        if (current == pos[i]) {
            safe = false;
            break;
        }
    }

    return safe;
}


int main()
{
    io;
    vector<pair<int, int> > pos = {{-1, -5}, {-1, -6},{-1, -7}, {6, -3}, {5, -3},
    {5, -4}, {5, -5}, {4, -5}, {3, -5}, {3, -4}, {3, -3}, {2, -3}, {1, -3},
    {0, -3}, {0, -2}, {0, -1}};

    pair<int, int> start = {-1, -7};
    while (start.first != 7){
        start.first ++;
        pos.push_back(start);
    }
    while (start.second != -3){
        start.second ++;
        pos.push_back(start);
    }

    char dir;
    int l;

    bool safe;
    pair<int, int> current = {-1, -5};
    while (true){
        cin >> dir >> l;
        safe = true;

        int add;
        if (dir == 'l') {
            add = 0;
            while (add < l){
                current.first -= 1;
                add ++;

                if (!isSafe(current, pos)) safe = false;
                pos.push_back(current);
            }
        }

        else if (dir == 'r') {
            add = 0;
            while (add < l){
                current.first += 1;
                add ++;

                if (!isSafe(current, pos)) safe = false;
                pos.push_back(current);
            }

        }
        else if (dir == 'd') {
            add = 0;
            while (add < l){
                current.second -= 1;
                add ++;

                if (!isSafe(current, pos)) safe = false;

                pos.push_back(current);
            }
        }

        else if (dir == 'u') {
            add = 0;
            while (add < l){
                current.second += 1;
                add ++;

                if (!isSafe(current, pos)) safe = false;
                pos.push_back(current);
            }

        }
        else break;

        if (safe){
            cout << current.first << " " << current.second << " safe" << endl;
        }
        else {
            cout << current.first << " " << current.second << " DANGER" << endl;
            break;
        }
    }


 	return 0;
}
