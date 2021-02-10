ll dist[100000];
int n;

// credit to CPI
void dijkstra(int src){
    for (int i = 0; i < n; i++)
        dist[i] = LLONG_MAX;

    using T = pair<ll,int>; priority_queue<T,vector<T>,greater<T>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (pq.size()){
        ll cdist, node;
        tie(cdist, node) = pq.top();
        pq.pop();

        if (cdist != dist[node])
            continue;
        for (auto i : graph[node]){
            // if we can reach a neighbouring node
            // faster, we update its min distance
            if (cdist + i.ss < dist[i.ff]){
                pq.push({dist[i.ff] = cdist + i.ss, i.ff});
            }
        }
    }
}
