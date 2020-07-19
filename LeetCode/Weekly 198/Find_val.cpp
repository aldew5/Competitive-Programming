/*
Aldew
credit to tmwilliamlin
Find a Value of a Mysterious Function Closest to Target
*/

class Solution {
public:
    // notice that there can be at most nlog(maxA_i)
    // different values so we can just check them all
    int closestToTarget(vector<int>& arr, int target) {
        // this set will contain all distinct possible 
        // values that end at i
        set<int> s;
        int ans = 1e9;
        for (int i = 0; i < arr.size(); i++){
            set<int> ns;
            // insert just the element
            ns.insert(arr[i]);
            for(auto a : s){
                // find new values by anding the values in 
                // s with the new number
                // now ns will store all values of the sub array
                // that end at i
                ns.insert(a & arr[i]);
            }
            // update the answer
            for (auto a : ns){
                ans = min(ans, abs(a-target));
            }
            s = ns;
        }
        return ans;
    }
};
