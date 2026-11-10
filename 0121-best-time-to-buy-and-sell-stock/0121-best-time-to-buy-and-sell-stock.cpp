class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;
        int maxProfit = 0;
        int n = prices.size();
        int mini = prices[0];
        for(int i = 1; i < n; i++){
            profit = prices[i] - mini;
            maxProfit = max(maxProfit, profit);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};