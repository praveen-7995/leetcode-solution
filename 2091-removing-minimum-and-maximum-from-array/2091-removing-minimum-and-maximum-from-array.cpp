class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIndex = 0;
        int maxIndex = 0;

        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < nums[minIndex]){
                minIndex = i;
            }
            if(nums[i] > nums[maxIndex]){
                maxIndex = i;
            }
        }
        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        int front = right + 1; 
        int back = n - left;
        int midle = (left + 1) + (n - right);
        return min({front, back, midle});
        
    }
};