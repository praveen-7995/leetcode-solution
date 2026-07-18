class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minVal = nums[0];
        int maxVal = nums[0];

        for (int x : nums) {
            minVal = min(minVal, x);
            maxVal = max(maxVal, x);
        }

        return __gcd(minVal, maxVal);
    }
};
