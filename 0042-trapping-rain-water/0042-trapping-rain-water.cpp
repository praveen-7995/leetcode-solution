class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1; 
        int lmax = 0, rmax = 0;
        int total = 0;

        while(left < right){
            if(height[left] <= height[right]){
                if(height[left] >= lmax){
                    lmax = height[left];
                }else {
                    total += lmax - height[left];
                }
                left++;
            }
            else{
                if(height[right] >= rmax){
                    rmax = height[right];

                }else {
                    total += rmax - height[right];
                }
                right--;
            }
        }

        return total;
        
    }
};
