/*
Aldew
PROB: Fencing
CLASSIFICATION:
DIFFICULTY:
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;

using namespace std;


/*
Take in all the coordinate input first.
Start by assuming the worst case for each plant (that
it's surrounded by weeds on both sides). Then check whether
there is are adjacent plant(s) and subtract from the
resulting fence length accordingly.

Since we don't require ordering it's much more efficient to
use unordered sets and maps.
*/
int main()
{
    io;

    int t;
    cin >> t;
    while (t--) {

        int n, m, k;
        cin >> n >> m >> k;

        vector<pair<int, int>> p;
        // create two unordered maps
        // each set in a will represent a row and the indexes
        // containing plants will be contained within the set
        // in b each set is a column containing rows with plants
        unordered_map<int, unordered_set<int> > a, b;

        while (k--) {
            int r, c;
            cin >> r >> c;

            //append the new pair of plant coordinates
            p.push_back({r,c});

            // keep track of the rows in columns that contain
            // plants
            a[r].insert(c);
            b[c].insert(r);
        }

        //sort the coordinates by the row numbers
        sort(p.begin(), p.end());

        int minl = 0;
        // iterate over the points in p
        for (auto P : p){
            // set i and j to be the r and c coords
            // of the plant
            int i = P.first, j = P.second;

            // start by adding 4 to the min length
            // assuming that this plant isn't adjacent
            // to any other plants
            minl += 4;

            // there are other plants in the row
            if (a.count(i)) {
                // in that row, if there is an adjacent plant
                // on either side there is no need for a fence
                if (a[i].count(j + 1)) minl -= 1;
                if (a[i].count(j - 1)) minl -= 1;
            }
            // there are other plants in that column
            if (b.count(j)) {
                // if the plants in the column are adjacent
                // to P subtract a fence
                if (b[j].count(i + 1)) minl -= 1;
                if (b[j].count(i - 1)) minl -= 1;
            }
        }
        cout << minl << endl;
    }

 	return 0;
}
