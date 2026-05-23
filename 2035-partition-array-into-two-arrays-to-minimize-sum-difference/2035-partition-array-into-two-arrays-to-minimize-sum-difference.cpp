class Solution {
public:
    
    void generate(vector<int>& nums, int start, int end, vector<vector<int>>& sums) {
        int len = end - start;

        for(int mask = 0; mask < (1 << len); mask++) {
            int sum = 0;
            int count = 0;

            for(int i = 0; i < len; i++) {
                if(mask & (1 << i)) {
                    sum += nums[start + i];
                    count++;
                }
            }

            sums[count].push_back(sum);
        }
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        int totalSum = 0;
        for(int num : nums) {
            totalSum += num;
        }

        vector<vector<int>> left(half + 1);
        vector<vector<int>> right(half + 1);

        generate(nums, 0, half, left);
        generate(nums, half, n, right);

        for(int i = 0; i <= half; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int ans = INT_MAX;

        for(int leftCount = 0; leftCount <= half; leftCount++) {
            int rightCount = half - leftCount;

            for(int leftSum : left[leftCount]) {
                int target = totalSum / 2 - leftSum;

                auto& vec = right[rightCount];
                auto it = lower_bound(vec.begin(), vec.end(), target);

                if(it != vec.end()) {
                    int selectedSum = leftSum + *it;
                    int otherSum = totalSum - selectedSum;
                    ans = min(ans, abs(selectedSum - otherSum));
                }

                if(it != vec.begin()) {
                    --it;
                    int selectedSum = leftSum + *it;
                    int otherSum = totalSum - selectedSum;
                    ans = min(ans, abs(selectedSum - otherSum));
                }
            }
        }

        return ans;
    }
};