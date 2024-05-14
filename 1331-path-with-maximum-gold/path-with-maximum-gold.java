class Solution {
    int[] dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
    public int getMaximumGold(int[][] grid) {
        int n = grid.length, m = grid[0].length, ans = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j] > 0)
                    ans = Math.max(ans, dfs(grid, i, j, n, m));
        return ans;
    }

    public int dfs(int[][] grid, int row, int col, int n, int m){
        int val = grid[row][col], ret = 0;
        grid[row][col] = 0;
        for(int i = 0; i < 4; ++i)
            if(valid(row + dx[i], col + dy[i], n, m) && grid[row + dx[i]][col + dy[i]] > 0)
                ret = Math.max(ret, dfs(grid, row + dx[i], col + dy[i], n, m));
        grid[row][col] = val;      
        return ret + val;
    }

    public boolean valid(int row, int col, int n, int m){
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
}