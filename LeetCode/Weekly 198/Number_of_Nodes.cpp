/*
Aldew
credit to tmWilliamlin
Number of Nodes in the Sub-Tree With Same Label
*/

class Solution {
public:
    // adjacency list
    vector<vector<int>> adj;
    string l;
    vector<int> ans;
    // stores how many times each character has been seen
    int c[26] = {};
    
    // start dfs from the root
    void dfs(int u = 0, int p = -1){
        //lc stores count before entering the subtree
        int lc = c[l[u] - 'a']++;
        // visit all nodes in the subtree
        for (int v : adj[u]){
            if (v^p) 
                dfs(v, u);
        }
        // take the total number of this type seen - what we had before
        // this results in only new labels
        ans[u] = c[l[u] - 'a'] - lc;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj = vector<vector<int>>(n);
        // build a tree
        for (auto e : edges){
            // create a vector of adjacent nodes for each node
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        l = labels;
        ans = vector<int>(n);
        dfs();
        return ans;
    }
};
