class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();
        int curr = 0;

        vector<int> prefixGcd(n, 0);

        for (int i = 0; i < n; i++) {
            curr = max(curr, nums[i]);
            prefixGcd[i] = gcd(nums[i], curr);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long gcdfixsum = 0;

        int left = 0;
        int right = n - 1;

        while (left < right) {
            gcdfixsum += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }

        return gcdfixsum;
    }
};