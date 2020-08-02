/*
Create a 1D vector representing the number of zeros
each row has at its end then go through the values and 
check if there is a valid number of zeros. If there is compute
the amount of moves and add it to ans otherwise return 0. Always
reorganize the grid after each move to represent the swaps.
*/

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        // num rows
        int n = grid.size();
        // store the number of zeros in each row
        vector<int> v(n);
        
        // loop through rows
        for (int i = 0; i < n ;i++){
            // there are less than n zeros and the value we're looking at it zero
            while (v[i] < n && grid[i][n-v[i] -1] == 0){
                // this counts the number of zeros before the first 1
                // starting from the 
                v[i] ++;
            }
        }
        
        int ans = 0;
        // loop through v
        for (int i = 0; i < n; i++){
            int j= i;
            // go through values in v after i 
            // the value must be less than the number of zeros needed
            while (j < n && v[j] < n -1 - i)
                j ++;
            // we don't find a row with the right number of zeros
            if (j >= n)
                // impossible
                return -1;
            // add the difference (number of switches)
            ans += j - i;
            
            // reorganize the grid
            while (j > i){
                swap(v[j], v[j-1]);
                j--;
            }
        }
        return ans;
    }
};
