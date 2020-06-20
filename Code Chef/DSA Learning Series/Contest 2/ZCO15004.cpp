/*
Aldew (credit to aryan_guptaaa)
PROB: Rectangles
CLASSIFICATION: Math, searching
DIFFICULTY:
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <map>
#include <math.h>
#include <cstdio>
#include <stack>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main()
{
    io;
    ll n;
    cin >> n;

    vector<pair<ll, ll>> c;
    ll x, y;
    ll i, j;
    for (i = 0; i < n; i++){
        cin >> x >> y;
        c.push_back(make_pair(x, y));
    }
    sort(c.begin(), c.end());

    vector<ll> area;

    // distance x is the leftmost x coordinate (coordinate to border)
    ll dx = c[0].first;
    for (i = 1; i < n; i ++){
        // check if there is a greater distance than dx between
        // adjecent coordinates
        if ((c[i].first - c[i-1].first) > dx){
            dx = (c[i].first - c[i-1].first);
        }
    }

    // check the leftmost coord with the border
    if ((100000 - c[n-1].first) > dx){
        dx = (100000 - c[n-1].first);
    }
    // push back the largest possible area given the
    // greatest distance between points

    // This is the widest rectangle possible
    area.push_back(dx*500);

    ll xl = 0;
    ll xg = 100000;
    // loop through points and check the greatest
    // x boundaries possible for a given height c[i].second

    // we are essentially picking a height and expanding x on either
    // side until it can no longer be expanded (hit a lower point)
    for (i = 0; i < n; i ++){
        // set them to borders
        xl = 0;
        xg = 100000;

        // loop through coordinates after c[i] (greater x values)
        for (j = i + 1; j < n; j++){
            // the y coordinate is less, than this point will
            // cause a horizontal border
            if (c[j].second < c[i].second){
            // so we make c[j] a new bound on the right x coordinate so
            // that c[j] insn't inside the border
                xg = c[j].first;
                break;
            }
        }
        // loop through points before c[i] (smaller x values)
        for (j = i -1; j >= 0; j--){
            // if the y coordinate is less t
            if (c[j].second < c[i].second){
                // set the left boundary to the x coordinate of the lower
                // point so the rectangle remains valid
                xl = c[j].first;
                break;
            }
        }
        // valid rectangle with width bounded by xg and xl and heigh bounded
        // by c[i].second
        area.push_back((xg-xl)*c[i].second);
    }
    // print the greatest area
    sort(area.begin(), area.end());
    cout << area[area.size() -1] << endl;


    return 0;
}





