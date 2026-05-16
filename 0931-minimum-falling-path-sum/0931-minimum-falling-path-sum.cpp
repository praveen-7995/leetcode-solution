class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));


        for(int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {

                int up = dp[i-1][j];

                int leftDiag = INT_MAX;
                if(j > 0)
                    leftDiag = dp[i-1][j-1];

                int rightDiag = INT_MAX;
                if(j < m-1)
                    rightDiag = dp[i-1][j+1];

                dp[i][j] = matrix[i][j] + min(up, min(leftDiag, rightDiag));
            }
        }

        int ans = INT_MAX;
        for(int j = 0; j < m; j++) {
            ans = min(ans, dp[n-1][j]);
        }

        return ans;
    }
};