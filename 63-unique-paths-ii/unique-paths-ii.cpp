class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &g) {
        int n = g.size(), m = g[0].size();
        vector<vector<long long>> grid(n, vector<long long>(m));
        for(int i = 0;i<n;++i)
            for(int j= 0;j<m;++j)
                grid[i][j] = g[i][j];
        if(grid[n-1][m-1] == 1 || grid[0][0] == 1)
            return 0;
        grid[n - 1][m - 1] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (grid[i][j] == 1 && (i != n - 1 || j != m - 1)) {
                    grid[i][j] = -1;
                    continue;
                }
                bool down = valid(i + 1, j, n, m), right = valid(i, j + 1, n, m);
                if (down && grid[i + 1][j] != -1)
                    grid[i][j] += grid[i + 1][j];
                if (right && grid[i][j + 1] != -1)
                    grid[i][j] += grid[i][j + 1];
            }
        }
        return grid[0][0];
    }

    bool valid(int row, int col, int n, int m) {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
};