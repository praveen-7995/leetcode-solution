class Solution {
public:

    int solve(int i, int M, vector<int>& suffix,
              vector<vector<int>>& dp) {

        int n = suffix.size() - 1;
        if(i == n) {
            return 0;
        }
        if(dp[i][M] != -1) {
            return dp[i][M];
        }

        int ans = 0;
        for(int X = 1; X <= 2 * M && i + X <= n; X++) {

            int newM = max(M, X);
            int opponent = solve(i + X, newM, suffix, dp);
            int current = suffix[i] - opponent;

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        vector<int> suffix(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        vector<vector<int>> dp(n + 1,
                               vector<int>(n + 1, -1));

        return solve(0, 1, suffix, dp);
    }
};