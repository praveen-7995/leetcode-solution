class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int>mp;
        for(int x : nums){
            mp.insert(x);
        }
        for(int i = 0; i <= nums.size(); i++){
            if(mp.find(i) == mp.end()){
                return i;
            }
        }
        return -1;
    }
};