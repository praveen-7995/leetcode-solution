class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int min_num = *min_element(nums.begin(), nums.end());
        int max_num = * max_element(nums.begin(), nums.end());
        unordered_set<int>missing(nums.begin(), nums.end());

        vector<int>ans;
        for(int i = min_num; i <= max_num; i++){
            if(missing.find(i) == missing.end()){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};