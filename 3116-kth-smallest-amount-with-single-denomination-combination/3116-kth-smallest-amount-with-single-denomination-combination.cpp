#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to calculate Greatest Common Divisor
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // Helper function to calculate Least Common Multiple
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    // Counts total unique multiples <= mid using Inclusion-Exclusion
    long long countMultiples(long long mid, vector<int>& coins) {
        long long count = 0;
        int n = coins.size();
        int totalSubsets = 1 << n; // 2^n total subsets

        // Iterate through all possible non-empty subsets of coins
        for (int i = 1; i < totalSubsets; i++) {
            long long currentLcm = 1;
            int elementCount = 0;

            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) { // If the j-th coin is included in the subset
                    currentLcm = lcm(currentLcm, coins[j]);
                    elementCount++;
                    
                    // Optimization: If LCM exceeds mid, its count contribution becomes 0
                    if (currentLcm > mid) break;
                }
            }

            // Odd number of elements -> Add to count
            // Even number of elements -> Subtract from count
            if (elementCount % 2 == 1) {
                count += mid / currentLcm;
            } else {
                count -= mid / currentLcm;
            }
        }
        return count;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // Binary search range setup
        // Minimum possible answer is 1
        long long low = 1; 
        
        // Maximum possible answer (smallest coin value * k)
        long long minCoin = *min_element(coins.begin(), coins.end());
        long long high = minCoin * k; 
        
        long long ans = high;

        // Perform Binary Search
        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countMultiples(mid, coins) >= k) {
                ans = mid;        // mid could be our answer
                high = mid - 1;   // Try to find a smaller valid amount
            } else {
                low = mid + 1;    // We need a larger number to reach k multiples
            }
        }

        return ans;
    }
};