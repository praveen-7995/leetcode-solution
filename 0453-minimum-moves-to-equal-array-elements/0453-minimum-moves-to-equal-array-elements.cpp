class Solution {
public:
    int minMoves(vector<int>& nums) {

        int mini = *min_element(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        for(int i = 0; i <n; i++){
            count += nums[i] - mini;
        }
        return count;
    }
};