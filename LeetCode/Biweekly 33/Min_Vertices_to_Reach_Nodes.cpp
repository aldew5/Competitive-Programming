/*
Just include the nodes that can't be reached by any edge
(their indegree is 0).
*/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> indeg(n);
        // loop through the edges and save their indegree
        for (const auto& e : edges)
            indeg[e[1]] ++;
        
        vector<int> ans;
        for (int i = 0; i < n; i++){
            // if the indegree is zero, add it to the answer
            if (!indeg[i])
                ans.push_back(i);
        }
        return ans;
    }
};
