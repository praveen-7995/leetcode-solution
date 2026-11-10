class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        vector<int>dp(n+1, INT_MAX);

        dp[0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = max(0, i-3); j < i; j++){
                int jump = (j - i) * (j - i);
                int totalCost = dp[j] +costs[i-1] + jump;

                dp[i] = min(dp[i], totalCost);
            }
        }
        return dp[n];
    }
};