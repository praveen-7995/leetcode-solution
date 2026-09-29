class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& grid, int r, int c, int balance) {
        // Invalid balance
        if (balance < 0)
            return false;

        // Too many '(' to possibly close
        if (balance > (n - r) + (m - c) - 1)
            return false;

        // Reached destination
        if (r == n - 1 && c == m - 1)
            return balance == 0;

        if (dp[r][c][balance] != -1)
            return dp[r][c][balance];

        // Move down
        bool down = false;
        if (r + 1 < n) {
            int newBalance = balance + 
                (grid[r + 1][c] == '(' ? 1 : -1);

            down = solve(grid, r + 1, c, newBalance);
        }

        // Move right
        bool right = false;
        if (c + 1 < m) {
            int newBalance = balance + 
                (grid[r][c + 1] == '(' ? 1 : -1);

            right = solve(grid, r, c + 1, newBalance);
        }

        return dp[r][c][balance] = down || right;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // Path length must be even
        if ((n + m - 1) % 2 != 0)
            return false;

        // Must start with '('
        if (grid[0][0] != '(')
            return false;

        dp.assign(n, vector<vector<int>>(
            m, vector<int>(n + m + 1, -1)
        ));

        return solve(grid, 0, 0, 1);
    }
};