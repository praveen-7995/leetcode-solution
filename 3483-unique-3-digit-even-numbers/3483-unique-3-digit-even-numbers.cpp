class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> uniqueNumbers; // Automatically filters out duplicate configurations
        int n = digits.size();
        
        // Loop for the Hundreds place
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) continue; // Leading zeros are not allowed
            
            // Loop for the Tens place
            for (int j = 0; j < n; j++) {
                if (j == i) continue; // Cannot reuse the same digit index
                
                // Loop for the Units place
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue; // Cannot reuse index i or j
                    
                    // The number must end in an even digit
                    if (digits[k] % 2 == 0) {
                        int currentNum = (digits[i] * 100) + (digits[j] * 10) + digits[k];
                        uniqueNumbers.insert(currentNum);
                    }
                }
            }
        }
        
        // Return the final count of unique numbers
        return uniqueNumbers.size();
    }
};