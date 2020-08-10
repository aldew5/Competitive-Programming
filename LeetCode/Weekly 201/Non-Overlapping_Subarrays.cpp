/*
Keep a set containing the prefix sums of all valid subarrays 
up to i. If we find a valid sum remove elements before the index
of that sum from the subarray and look for the next one. 

We check if ps - target is in the set. If it is we know that
the difference between two prefix sums is the target.
*/

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        set<int> s;
        // start with zero
        s.insert(0);
        // prefix sum and ans
        int ps = 0, ans = 0;
        // loop through numbers
        for (int a : nums){
            // update the prefix sum
            ps += a;
            // check if ps - target exists in the set
            // if it exists then we know there is a value
            // such that value + target = ps
            // therefore the numbers after value have a sum of target
            if (s.find(ps - target) != s.end()) {
                ans ++;
                // clear the set because these prefix sums
                // are now in a used range. If we used them
                // our subsets would overlap
                s.clear();
            }
            // insert the new value
            s.insert(ps);
        }
        return ans;
    }
};
