class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int min_sum = INT_MAX;

        for(int i = 0; i < n; i++){
            int currentSum = 0;
            for(int j = i; j < n; j++){
                currentSum += nums[j];

                int length = j-i+1;
                if(length >= l && length <= r && currentSum > 0){
                    min_sum = min(min_sum , currentSum);
                }
            }
        }
        return (min_sum == INT_MAX) ? -1 : min_sum;
    }
};