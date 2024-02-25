class Solution {
public:
    int n, m;
    vector<int> dx, dy;
    vector<vector<bool>> vis;
    vector<vector<char>> grid;

    int numIslands(vector<vector<char>> &g) {
        grid = g;
        n = grid.size(), m = grid[0].size();
        vis.resize(n, vector<bool>(m));
        dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (valid(i, j))
                    dfs(i, j), ++ans;
            }
        return ans;
    }

    void dfs(int row, int col) {
        vis[row][col] = true;
        for (int i = 0; i < 4; ++i) {
            int newX = row + dx[i], newY = col + dy[i];
            if (valid(newX, newY))
                dfs(newX, newY);
        }
    }

    bool valid(int row, int col) {
        return (row >= 0 && row < n && col >= 0 && col < m && !vis[row][col] && grid[row][col] == '1');
    }
};