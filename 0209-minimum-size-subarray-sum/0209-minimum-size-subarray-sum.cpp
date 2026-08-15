class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();
        int sum = 0;
        int left = 0;
        int maxLength = INT_MAX;
        for(int right = 0; right < n; right++){
            sum += nums[right];
            while(sum >= target){
                maxLength = min(maxLength , right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        if(maxLength == INT_MAX){
            return 0;
        }
        return maxLength;
        
    }
};