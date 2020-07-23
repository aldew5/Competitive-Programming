/*
ID: alec3
LANG: C++14
PROG: lamps
credit to Russ Cox
*/
/*
No matter which switches are pressed, the light pattern will repeat every six lamps.
This is just the nature of the changes the buttons make. The order you press the switches
doesn't matter (pushing button A at the end is the same as pushing it at the start).

Also any even number of switch presses greater than four might is the same as four switch
presses, and any odd number grerater than three is the same as three presses.
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

const int MAXLAMP = 6;
const int LAMPMASK = ((1 << MAXLAMP) -1);

// these are initialized to zero
int nlamp, nswitch, ison, known;
int poss[1 << MAXLAMP];

ifstream fin("lamps.in");
ofstream fout("lamps.out");

// since we treat the lights as bit vector we can manipulate
// them with bitwise manipulations
int flip[4] = {
    LAMPMASK, // flip all lights
    LAMPMASK & 0xAA, // flip odd lights
    LAMPMASK & 0x55, // even lights
    LAMPMASK & ((1 << (MAXLAMP-1)) | (1 << (MAXLAMP-4))) // lights 1 and 4
};

// the sequence starts with state lights, then we flip exactly n swithces
// with number >= i;
void solve(int lights, int i, int n){
    // base case
    if (n == 0){
        // if the lights are on in the right positions
        if ((lights & known) == ison)
            // possible scenario
            poss[lights] = 1;
        return;
    }
    // 
    for (; i < 4; i++){
        solve(lights ^ flip[i], i + 1, n-1);
    }
}
void print (int lights){
    char s[100+1];

    for(int i = 0; i < nlamp; i++)
        s[i] = (lights & (1<<(MAXLAMP - 1 - i % MAXLAMP))) ? '1' : '0';
    s[nlamp] = '\0';

    fout << s << endl;
}



int main()
{
    fin >> nlamp >> nswitch;

    int a;
    // reading ON lamps
    while (true){
        // a is a lamp index
        fin >> a;
        if (a == -1)
            break;
    
        // computing a mod 6, zero index it to 
        // find it's position in the bit vector
        a = MAXLAMP - 1 - (a-1) % MAXLAMP;
        // the ath bit of ison and known will be one
        ison |= 1 << a;
        known |= 1 << a;
    }

    // reading OFF lamps
    while (true){
        fin >> a;
        if (a == -1)
            break;

        a = MAXLAMP - 1 - (a-1) % MAXLAMP;
        known |= 1 << a;

    }
    
    // based on logic at top
    if (nswitch > 4){
        if (nswitch % 2 == 0)
            nswitch = 4;
        else
            nswitch = 3;
    }
    
    
    for (; nswitch >= 0; nswitch -= 2){
        solve(LAMPMASK, 0, nswitch);
    }

    bool impossible = true;
    for (int i = 0; i < (1 << MAXLAMP); i++){
        if (poss[i]){
            print(i);
            impossible = false;
        }
    }

    if (impossible)
        fout << "IMPOSSIBLE" << endl;


    return 0;

}
