class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n, vector<int>(m));

        k %= (n * m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int idx = i * m + j;
                int newIdx = (idx + k) % (n * m);

                int newRow = newIdx / m;
                int newCol = newIdx % m;

                ans[newRow][newCol] = grid[i][j];
            }
        }

        return ans;
    }
};