class Solution {
public:
    int n, m;
    vector<int> dx, dy;

    int numIslands(vector<vector<char>> &grid) {
        n = grid.size(), m = grid[0].size();
        dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1')
                    dfs(i, j, grid), ++ans;
            }
        return ans;
    }

    void dfs(int row, int col, vector<vector<char>> &grid) {
        grid[row][col] = '0';
        for (int i = 0; i < 4; ++i) {
            int newX = row + dx[i], newY = col + dy[i];
            if (valid(newX, newY, grid))
                dfs(newX, newY, grid);
        }
    }

    bool valid(int row, int col, vector<vector<char>> &grid) {
        return (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == '1');
    }
};