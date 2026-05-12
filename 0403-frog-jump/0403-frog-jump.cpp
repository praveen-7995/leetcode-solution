class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if(stones[1] != 1) return false;
        unordered_map<int, unordered_set<int>> dp;

        dp[1].insert(1);

        for(int i = 1; i < n; i++){
            int position = stones[i];

            for(int jump : dp[position]){
                for(int nextJump : {jump - 1, jump, jump +1}){
                    if(nextJump > 0){
                        int nextPos = position + nextJump;

                        if(binary_search(stones.begin(), stones.end(), nextPos)){
                            dp[nextPos].insert(nextJump);
                        }
                    }
                }
            }
        }
        return !dp[stones[n - 1]].empty();
        
    }
};