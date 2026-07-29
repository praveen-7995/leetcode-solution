class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        
        int left = 0, right = 0;
        int sum = 0, cnt = 0;
        int n = nums.size();

        while (right < n) {
            sum += nums[right];
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }
            cnt += (right - left + 1);
            right++;
        }

        return cnt;
    }
};