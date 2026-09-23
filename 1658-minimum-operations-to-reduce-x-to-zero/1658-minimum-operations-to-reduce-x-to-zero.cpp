class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = 0;
        
        // Calculate the sum of all elements
        for (int num : nums) {
            totalSum += num;
        }
        
        // Target sum for the middle subarray
        int target = totalSum - x;
        
        // If target is 0, we need to remove all elements
        if (target == 0) return n;
        // If target is negative, it's impossible to reduce x to 0
        if (target < 0) return -1;
        
        int maxLength = -1;
        int currentSum = 0;
        int left = 0;
        
        // Sliding window to find the longest subarray summing to 'target'
        for (int right = 0; right < n; right++) {
            currentSum += nums[right];
            
            // Shrink the window from the left if the current sum exceeds target
            while (currentSum > target && left <= right) {
                currentSum -= nums[left];
                left++;
            }
            
            // Check if we found a valid subarray
            if (currentSum == target) {
                maxLength = max(maxLength, right - left + 1);
            }
        }
        
        // If no valid subarray was found, return -1. 
        // Otherwise, subtract the longest subarray length from total elements.
        return (maxLength == -1) ? -1 : n - maxLength;
    }
};