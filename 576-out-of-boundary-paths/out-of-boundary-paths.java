class Solution {
    int dp[][][];

    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp = new int[m + 2][n + 2][maxMove + 2];
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++)
                for (int k = 0; k <= maxMove; k++)
                    dp[i][j][k] = -1;
        return solve(m, n, maxMove, 0, startRow, startColumn);
    }

    public int solve(int m, int n, int maxMove, int moves, int r, int c) {
        if (moves > maxMove)
            return 0;
        if (r >= m || c >= n || r < 0 || c < 0)
            return 1;
        if (dp[r][c][moves] != -1)
            return dp[r][c][moves];

        dp[r][c][moves] = (solve(m, n, maxMove, moves + 1, r + 1, c)) % 1000000007;
        dp[r][c][moves] += solve(m, n, maxMove, moves + 1, r, c + 1);
        dp[r][c][moves] %= 1000000007;
        dp[r][c][moves] += solve(m, n, maxMove, moves + 1, r - 1, c);
        dp[r][c][moves] %= 1000000007;
        dp[r][c][moves] += solve(m, n, maxMove, moves + 1, r, c - 1);
        dp[r][c][moves] %= 1000000007;
        return dp[r][c][moves];
    }
}