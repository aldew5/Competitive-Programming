
// Credit to usaco guide
ll prim(){
	ll weight = 0;
	vector<bool> selected(n, false);
	vector<ll> min(n, MAX);
	min[0] = 0;
	set<pl> q;
	q.insert({0, 0});
	vector<bool> visited(n, false);
	for (int i = 0; i < n; ++i) {
		if (q.empty()) {
			return -1;
		}
		int v = q.begin() -> s;
		visited[v] = true;
		weight += q.begin()-> f;
		q.erase(q.begin());

		for (pl e : adj[v]) {
			if(!visited[e.s] && e.f < min[e.s]) {
				q.erase({min[e.s], e.s});
				min[e.s] = e.f;
				q.insert({e.f, e.s});
			}
		}
	}
	return weight;
}
