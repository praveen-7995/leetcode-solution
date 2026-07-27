class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        int maxProduct = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int product = (nums[i] - 1) * (nums[j]-1);
                 maxProduct = max(maxProduct , product);
            }
        }
        
        return maxProduct;
    }
};