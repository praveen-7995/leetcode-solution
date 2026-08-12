class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int maxLength = 0;
        int left = 0;
        unordered_map<int,int>mp;
        for(int right = 0; right < nums.size(); right++){
            mp[nums[right]]++;
            while(mp[nums[right]] > k){
                mp[nums[left]]--;
                left++;
            }
            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;

        
    }
};