/*
We count the ones because each one either represents a multiplication
by two, or an addition by one (if it's the first-order term). No matter
what operation it is, it still costs a move.

Adding the position of the highest order one in all the numbers
accounts for the intermediate zeros (eg. 00100000 would only increase the answer
by one in the first loop, but it costs a lot more. Since we can multiply numbers
simultaneously, we only have to look at the greatest number.
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int best = 0, ans = 0;
        
        for (int num: nums){
            // at the number of ones in the binary representation of
            // each number to ans
            ans += __builtin_popcount(num);
            // save the largest number
            best = max(best, num);
        }
        
        // loop through the bits in the biggest number
        for (int i = 29; i >= 0; i--){
            // find the highest order 1
            if (best & (1 << i)){
                // add the position to ans
                ans += i;
                break;
            }
        }
        return ans;
    }
};
