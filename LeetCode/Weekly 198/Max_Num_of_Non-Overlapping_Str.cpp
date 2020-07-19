class Solution {
public:
    #define ar array
    bool adj[26][26], vis[26];
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> p[26];
        for (int i = 0; i < s.size(); i++){
            p[s[i] - 'a'].push_back(i);
        }
        // construct adjecency lists
        for (int i = 0; i < 26; i++){
            for (int j = 0; j < 26; j++){
                if (p[i].size() && p[j].size() && lower_bound(p[i].begin(), p[i].end(), p[j][0]) != lower_bound(p[i].begin(), p[i].end(), p[j].back())){
                    adj[j][i] = 1;
                }
            }
        }
        // use Floyd-Warshall to find ranges
        for (int k = 0; k < 26; k++){
            for (int i = 0; i < 26; i++){
                for (int j = 0; j < 26; j++){
                    adj[i][j] |= adj[i][k] && adj[k][j];
                }
            }
        }
        vector<ar<int, 2>> v;
        for (int i = 0; i < 26; i++){
            if(p[i].size()){
                bool ok = 1;
                // if there exists a char j such that we can go from
                // i to j but not fron j to i then don't include i
                for (int j = 0; j < 26; j++){
                    if (adj[i][j] && !adj[j][i]) 
                        ok = 0;
                }
                // otherwise add to the list of ranges
                if (ok)
                    v.push_back({p[i][0], p[i].back()});                                         }
        }
       bool ch=1;
        while(ch) {
            ch=0;
            // check each pair
            for(int i=0; i< v.size(); ++i) {
                for(int j=0; j< v.size() && !ch; ++j) {
                    if(i==j)
                        continue;
                    // if there's an intersection
                    if(v[i][0]<=v[j][0] && v[j][0]<=v[i][1]) {
                        auto a=v[i], b=v[j];
                        // remove from the list
                        v.erase(find(v.begin(), v.end(), a));
                        v.erase(find(v.begin(), v.end(), b));
                        // and merge them
                        v.push_back({a[0], max(a[1], b[1])});
                        ch=1;
                    }
                }
            }
        }
        vector<string> ans;
        for(auto a : v)
            // convert ranges to strings and output
            ans.push_back(s.substr(a[0], a[1]-a[0]+1));
        return ans;
    }
};
