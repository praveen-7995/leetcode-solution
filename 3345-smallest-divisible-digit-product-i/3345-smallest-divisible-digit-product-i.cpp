class Solution {
public:
    int getDigits(int num){
        int product = 1;
        while(num > 0){
            product *= (num % 10);
            num /= 10;
        }
        return product;

    }
    int smallestNumber(int n, int t) {

        while(getDigits(n)% t != 0){
            n++;
        }
        return n;
        
    }
};