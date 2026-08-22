class Solution {
public:
    bool checkDivisibility(int n) {

        int orginal = n; 
        int productSum = 0;
        int product = 1;
        while(n > 0){
            int digit = n % 10;
            productSum += digit;
            product *= digit;
            n /= 10;
        }
         int sum = productSum + product;
         if(orginal % sum == 0) return true;
         return false;
    }
};