class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> prefix(2 * limit + 2, 0);

        for(int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            int left = min(a, b) + 1;
            int right = max(a, b) + limit;
            int sum = a + b;
            prefix[2] += 2;
            prefix[left] -= 1;
            prefix[right + 1] += 1;
            prefix[sum] -= 1;
            prefix[sum + 1] += 1;
        }

        int ans = INT_MAX;
        int moves = 0;

        for(int s = 2; s <= 2 * limit; s++) {
            moves += prefix[s];
            ans = min(ans, moves);
        }

        return ans;
    }
};