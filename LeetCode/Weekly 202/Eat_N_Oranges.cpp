/*
A classic dynamic programming problem. Compute the answers for smaller days
that n will reach and use those to build up to n.
*/

class Solution {
public:
    unordered_map<int, int> dp;
    int calc(int n){
        if (n == 0)
            return 0;
        // no solution stored
        if (dp.find(n) == dp.end()){
            // max days possible
            int d = n;
            // best solution for n/2 days + 1 (last day takes 1 day) +
            // remainder which must be subtracted
            d = min(calc(n/2) + 1 + n % 2, d);
            // and n/3 days
            d = min(calc(n/3) + 1 + n % 3, d);
            // update dp
            dp[n] = d;
        }
        // output
        return dp[n];
    }
    
    int minDays(int n) {
        return calc(n);
    }
};
