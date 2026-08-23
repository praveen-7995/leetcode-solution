class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();
        vector<bool>dp(n+1, false);

        dp[0] = true;
        for(int i = 0; i<= n; i++){
            if(!dp[i]) continue;
            string temp = "";
            for(int j = i; j < n; j++){
                temp += s[j];
                if(find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()){
                    dp[j+1] = true;
                }
            }
        }

        return dp[n];
        
    }
};