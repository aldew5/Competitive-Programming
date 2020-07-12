/*
ID: alec3
LANG: C++14
PROG: Knight Hop
CLASSIFICATION: BFS
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };

bool valid(int x, int y){
    if (x <= 8 && y <= 8 && x > 0 && y > 0) return true;
    else return false;
}

struct Node
{
	// (x, y) represents chess board coordinates
	// dist represent its minimum distance from the source
	int x, y, dist;

	// Node constructor
	Node(int x, int y, int dist = 0): x(x), y(y), dist(dist) {}

	// As we are using struct as a key in a std::set,
	// we need to overload < operator
	// Alternatively we can use std::pair<int, int> as a key
	// to store coordinates of the matrix in the set

	bool operator<(const Node& o) const
	{
		return x < o.x || (x == o.x && y < o.y);
	}
};

// Find minimum number of steps taken by the knight
// from source to reach destination using BFS
int BFS(Node src, Node dest)
{
	// set to check if matrix cell is visited before or not
	set<Node> visited;

	// create a queue and enqueue first node
	queue<Node> q;
	q.push(src);

	// run till queue is not empty
	while (!q.empty())
	{
		// pop front node from queue and process it
		Node node = q.front();
		q.pop();

		int x = node.x;
		int y = node.y;
		int dist = node.dist;

		// if destination is reached, return distance
		if (x == dest.x && y == dest.y)
			return dist;

		// Skip if location is visited before
		if (!visited.count(node))
		{
			// mark current node as visited
			visited.insert(node);

			// check for all 8 possible movements for a knight
			// and enqueue each valid movement into the queue
			for (int i = 0; i < 8; ++i)
			{
				// Get the new valid position of Knight from current
				// position on chessboard and enqueue it with +1 distance
				int x1 = x + row[i];
				int y1 = y + col[i];

				if (valid(x1, y1))
					q.push({x1, y1, dist + 1});
			}
		}
	}

	// return INFINITY if path is not possible
	return INT_MAX;
}

int main()
{
    io;
    int x, y;
    cin >> x >> y;

    Node pos = {x, y};
    cin >> x >> y;
    Node dest = {x, y};
    cout << BFS(pos, dest) << endl;


    return 0;
}
