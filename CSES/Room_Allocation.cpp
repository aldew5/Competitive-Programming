/*
ID: alec3
LANG: C++14
PROG:
/*
We can't iterate over all possibilities

We look at each pair of posts that have the same x or y coordinates (parallel).
We then go through all the other points and add |x-y|/2 * (y_p - y_x) or|x-y|/2 * (x_p - x_x) depening
on what axis the base is parallel to.
*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" " << endl;
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ld long double
#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define line cout << "--------------" << endl;

typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}


int n;
ll a, b;
int ans[200005];

int main()
{
    io;
    cin >> n;
    vector<pair<pair<int, int>, int> > v;

    int a, b;
    for (int i = 0; i < n; i++){
        // arrival and departure
        cin >> a >> b;
        // v[i].ss is the original index
        v.pb(mp(mp(a, b), i));
    }
    // sort the rooms by arrival time
    sort(v.begin(), v.end());

    int rooms = 0, last = 0;
    // min heap to store departure times (stores the soonest
    // departure time on top)
    priority_queue<pair<int, int> > pq;
    for (int i = 0; i < n; i++){
        // nobody's arrived yet
        if (pq.empty()){
            // add a room
            last++;
            // implement by making v[i] negative
            // add the new departure time to the min heap and the room number
            pq.push(make_pair(-v[i].ff.ss, last));
            ans[v[i].ss] = last;
        }

        else {
            // the earliest departure time is the top of the min heap
            pair<int, int> mini = pq.top();
            // the arrival time of the new person isn't
            // earlier than earliest departure time
            // this means that the new person can stay in this room
            if (-mini.ff < v[i].ff.ff) {
                pq.pop();
                // add the new person to the min heap and their room number
                pq.push(mp(-v[i].ff.ss, mini.ss));
                // add the room number to the answer
                ans[v[i].ss] = mini.ss;
            }

            else {
                // we need a new room
                last ++;
                // update the min heap and the answer
                pq.push(mp(-v[i].ff.ss, last));
                ans[v[i].ss] = last;
            }
        }
        // pq.size() is the number of different rooms we're using
        rooms = max(rooms, int(pq.size()));
    }
    cout << rooms << endl;
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
