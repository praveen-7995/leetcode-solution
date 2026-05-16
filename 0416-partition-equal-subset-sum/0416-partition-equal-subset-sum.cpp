class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int totalSum = 0;

        for(int num : nums){
            totalSum += num;
        }
        if(totalSum % 2 != 0) return false;

        int total = totalSum / 2;


        vector<bool>dp(total + 1, false);
        dp[0] = true;

        for(int x : nums){
            for(int j = total; j >= x; j--){
                dp[j] = dp[j] || dp[j-x];
            }
        }
        return dp[total];
        
    }
};