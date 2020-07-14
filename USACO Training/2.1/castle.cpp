/*
ID: alec3
LANG: C++14
PROG: castle
CLASSIFICATION: flood fill
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const int MAXDIM = 50;
const int MAXN = 100;
const int MAXCOLOR  = 100;
const int MAXROOM = (MAXDIM*MAXDIM);

// create an enum to pair direction with value
enum {
    Wwest = 1,
    Wnorth = 2,
    Weast = 4,
    Wsouth = 8
};

// define a square as a section of the castle
struct Square{
    int wall;
    int numbered;
    int room;
};
int wid, ht;
// define the castle
Square castle[MAXDIM][MAXDIM];
int roomsize[MAXROOM];

// assigns each square with a number using a floodfill
// approach that can be used to differentiate rooms
void number(int room, int x, int y){
    int w;

    if (castle[x][y].numbered){
        // make sure if it's numbered the given room is correct
        assert(castle[x][y].room == room);
        return;
    }
    // set numbered to true and update vars
    castle[x][y].numbered = 1;
    castle[x][y].room = room;
    roomsize[room] ++;

    w = castle[x][y].wall;
    // try to expand the room in all directions using a floodfill

    // not the leftmost square or the leftmost wall
    if (x > 0 && !(w & Wwest)){
        number(room, x-1, y);
    }
    // not the rightmost square or the rightmost wall
    if (x + 1 < wid && !(w & Weast)){
        number(room, x+1, y);
    }

    if (y > 0 && !(w & Wnorth)){
        number(room, x, y-1);
    }

    if (y+1 < ht && !(w & Wsouth)){
        number(room, x, y+1);
    }
}

/*Use a DFS floodfill*/
int main()
{
    int w, nroom, bigroom;
    int n, m, mx, my;
    char mc;

    ifstream fin("castle.in");
	ofstream fout("castle.out");

    fin >> wid >> ht;

    // read walls and fill in castle array
    for (int y = 0; y < ht; y++){
        for (int x = 0; x < wid; x++){
            fin >> w;
            castle[x][y].wall = w;
        }
   }

    // current room
    nroom = 0;
    // loop through all squares and number them
    // as part of a room
    for (int y = 0; y < ht; y++){
        for (int x = 0; x < wid; x++){
            // if it isn't numbered number it
            if (!castle[x][y].numbered){
                number(nroom++, x, y);
            }
        }
    }

    // find biggest room
    bigroom = roomsize[0];
    for (int i = 1; i < nroom; i++){
        if (bigroom < roomsize[i]) bigroom = roomsize[i];
    }

    // find the best result that can come from removing an east
    // or north wall
    m = 0;
    for (int x = 0; x < wid; x++){
        for (int y = ht-1; y >= 0; y--){
            // different rooms
            if (y > 0 && castle[x][y].room != castle[x][y-1].room){
                // possible combined size
                n = roomsize[castle[x][y].room] + roomsize[castle[x][y-1].room];
                // new biggest combined room
                if (n > m){
                    // save the stats
                    m = n;
                    mx = x;
                    my = y;
                    mc = 'N';
                }
            }
            // check the other side
            if (x + 1 < wid && castle[x][y].room != castle[x+1][y].room){
                n = roomsize[castle[x][y].room] + roomsize[castle[x+1][y].room];
                if (n > m){
                    m = n;
                    mx = x;
                    my = y;
                    mc = 'E';
                }
            }

        }
    }
    // print results
    fout << nroom << endl;
    fout << bigroom << endl;
    fout << m << endl;
    fout << my + 1 << " " << mx + 1 << " "  << mc << endl;

    return 0;

}
