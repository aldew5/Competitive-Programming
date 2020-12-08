/*
ID: alec3
LANG: C++14
PROG:
/*
Credit to Oscar Garries

The worst congestion is going to happen right when the fans leave the 
area. We can do a linear scan of the tree and calculate the number of fans
on either side of a potential arena location. The optimal location is one in which
they are most balanced.
*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" " << endl;
#define line cout << "--------------" << endl;
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ld long double

#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, n) for (int i = 0; i < n; i++)


typedef long long ll;
typedef unsigned long long ull;

int pct(int x) { return __builtin_popcount(x); }

using namespace std;

void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}

int fans = 0;

vector<int> adj[(int)1e6], nodes(1e6), people(1e6), children(1e6);

void dfs(int v, int parent){
    // loop through every node that is connected to node v
    for (auto x : adj[v]){
        // if it's not the parent node (the node we came from [remember this is a tree])
        if (x == parent)
            continue;
        // dfs from here
        dfs(x, v);
        
        // v is the parent of x 
        // children[v] is the amount of people up to that point
        
        children[v] += children[x];
        // the people up to the vth node is the max people 
        people[v] = max(people[v], children[x]);
    }
    // we found a leaf
    // the people at the leaf is the max of those people and the total fans - all the people up to that point
    // - the number of people at the vth city
    // this leaves the number of fans on the other side
    people[v] = max(people[v], fans-children[v] - nodes[v]);
    // the children of city v increases by the number of people at v
    children[v] += nodes[v];

    return;
}

// number of cities, number of people in city i, roads between d[i] and s[i]
int LocateCentre (int n, int p[], int d[], int s[]){
    F0R(i, n){
        // count the total number of people
        fans += p[i];
        // copy p into nodes
        nodes[i] = p[i];
    }
    //make an adjacency list for the roads
    F0R(i, n-1){
        adj[s[i]].pb(d[i]);
        adj[d[i]].pb(s[i]);
    }
    
    // dfs from the first city (has no parent)
    dfs(0, -1);
    int sol = INT_MAX, ans = -1;
    
    
    // find the city (i) where people[i] is minimum
    F0R(i, n){
        if (people[i] < sol){
            ans = i;
            sol = people[i];
        }
    }
    return ans;
}

