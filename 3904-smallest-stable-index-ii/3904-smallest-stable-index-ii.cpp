class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>suffixmin(n);

        suffixmin[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            suffixmin[i] = min(suffixmin[i+1], nums[i]);
        }
        int largest = INT_MIN;
        for(int i = 0; i < n; i++){
            largest = max(largest, nums[i]);
            int diff = largest - suffixmin[i];
            if(diff <= k){
                return i;
            }
        }
        return -1;
    }
};