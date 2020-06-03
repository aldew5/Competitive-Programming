
/*
Aldew
PROBLEM: Two City Scheduling
*/

/*
Create a vector of pairs with each pair containing the optimal city and
how much that city will take away from the worst case. Go through that vector
and add the highest differences until a city is full in which case you must use the worst case
city for that person.
*/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans = 0;
        vector<pair<int, int>> dif;
 
        pair<int, int> val;
        for (int i = 0; i < costs.size(); i++){
            if (costs[i][0] < costs[i][1]) val = {costs[i][1] - costs[i][0], 0};
            else val = {costs[i][0] - costs[i][1], 1};
            ans += max(costs[i][0], costs[i][1]);
            
            dif.push_back(val);
        }
        sort(dif.rbegin(), dif.rend());
        
        int a = 0, b = 0;
        for (int i = 0; i < dif.size(); i++){
            if (dif[i].second == 0 && a < costs.size()/2) {
                a++;
                ans -= dif[i].first;
            }
            else if (dif[i].second == 1 && b < costs.size()/2){
                b ++;
                ans -= dif[i].first;
            }
            // outside limits
            else {
                if (dif[i].second == 0) b ++;
                else a ++;
            }
        }
        return ans;
    }
};
