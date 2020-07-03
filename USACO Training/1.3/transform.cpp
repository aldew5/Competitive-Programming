/*
ID: alec3
LANG: C++14
PROG: transform
CLASSIFICATION: brute force
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;

using namespace std;


int main()
{
    ofstream fout("transform.out");
    ifstream fin("transform.in");

    int n;
    fin >> n;
    char a[n][n];
    char b[n][n];

    char it;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            fin >> it;
            a[i][j] = it;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j ++){
            fin >> it;
            b[i][j] = it;
        }
    }

    bool good = true;
    bool orig = true;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] != b[i][j]) {
                orig = false;
                break;
            }
        }
    }


    //check reflection first
    int s = 0, e = n -1;
    char temp;

    bool trans = false;
    for (int i = 0; i < n; i++){
        s = 0, e = n -1;
        while (s < e){
            temp = a[i][s];
            a[i][s] = a[i][e];
            a[i][e] = temp;

            s ++;
            e --;
        }
    }

    trans = true;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] != b[i][j]) {
                trans = false;
                break;
            }
        }
    }

    // flip back
    for (int i = 0; i < n; i++){
        s = 0, e = n -1;
        while (s < e){
            temp = a[i][s];
            a[i][s] = a[i][e];
            a[i][e] = temp;

            s ++;
            e --;
        }
    }

    //rotate
    int c = 0, t = 0;
    while (c < 8){
        good = true;
        //transform over y axis
        if (c == 4){
            if (trans) break;

            s = 0, e = n -1;

            for (int i = 0; i < n; i++){
                s = 0, e = n -1;
                while (s < e){
                    temp = a[i][s];
                    a[i][s] = a[i][e];
                    a[i][e] = temp;

                    s ++;
                    e --;
                }
            }

        }

        for (int i = 0; i < n/2; i++){
            for (int j = i; j < n - i -1; j ++){
                int temp = a[i][j];
                a[i][j] = a[n-1-j][i];
                a[n-1-j][i] = a[n-1-i][n-1-j];
                a[n-1-i][n-1-j] = a[j][n-1-i];
                a[j][n-1-i] = temp;
            }
        }

        c ++;
        good = true;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (a[i][j] != b[i][j]) {
                    good = false;
                    break;
                }
            }
        }
        if (good) break;
    }

    if (c == 4 && trans){
        cout << 4 << endl;
        fout << 4 << endl;
    }

    else if (good && c < 4) {
        cout << c << endl;
        fout << c << endl;
    }
    else if (good && c >= 4) {
        cout << 5 << endl;
        fout << 5 << endl;
    }
    else if (orig){
        cout << 6 << endl;
        fout << 6 << endl;
    }
    else if (!good) {
        cout << 7 << endl;
        fout << 7 << endl;
    }

 	return 0;
}
