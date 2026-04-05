class Solution {
public:
    // make a vector of size cost+1 prefilled with 0s
    vector<int> dp;
    int minCostClimbingStairs(vector<int>& cost) {
        dp = vector<int>(cost.size() + 1, 0);
        dp[cost.size()-1] = cost[cost.size() - 1];
        int i = cost.size()-2;
        while (i>=0){
            dp[i] = min(cost[i] + dp[i+1],cost[i] + dp[i+2]);
            i--;
        }
        return min(dp[0],dp[1]);
    }
};
