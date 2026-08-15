class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int XOR = 0; 
        bool hasNonZero = false;
        for(int i = 0; i < n; i++){
            XOR ^= nums[i];
            if(XOR != 0){
                hasNonZero = true;
            }
        }
        if(!hasNonZero){
            return 0;
        }
        if(XOR != 0){
            return n;
        }
        return n-1;
        
    }
};