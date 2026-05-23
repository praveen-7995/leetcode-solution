class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return false ;

        int count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[(i + 1) % n]){
                count++;
            }
            if(count > 1) return false ;
        }
        return true;
        
    }
};