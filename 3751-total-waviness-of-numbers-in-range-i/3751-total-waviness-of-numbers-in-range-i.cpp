class Solution {
public: 
    int getwainess(int num){
        string s = to_string(num);
        int count = 0;
        if(s.size() < 3){
            return 0;
        }
        for(int i = 1; i < s.size()-1; i++){
            if(s[i] > s[i-1] && s[i] > s[i+1]){
                count++;
            }else if(s[i] < s[i-1] && s[i] < s[i+1]){
                count++;
            }
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int num = num1; num <= num2; num++){
            ans += getwainess(num);
        }
        return ans;
        
    }
};