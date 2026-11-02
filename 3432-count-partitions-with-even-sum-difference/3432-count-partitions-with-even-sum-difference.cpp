class Solution {
public:
    int countPartitions(vector<int>& nums) {

        int n = nums.size();
        int total = 0;
        for(int i = 0; i <n; i++){
            total += nums[i];
        }
        if(total % 2 != 0){
            return 0;
        }
        return n -1;
        
    }
};