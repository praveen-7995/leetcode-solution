class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        
        int oddsum = n * n;
        int evensum = n * (n +1);

        return gcd(oddsum, evensum);
    }
};