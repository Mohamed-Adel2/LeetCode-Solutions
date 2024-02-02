class Solution {
    int[][] dp;
    int[][] mat;

    public int minFallingPathSum(int[][] matrix) {
        dp = new int[matrix.length + 1][matrix.length + 1];
        for (int i = 0; i < matrix.length; i++)
            for (int j = 0; j < matrix.length; j++)
                dp[i][j] = 1000000000;
        mat = matrix;
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < matrix.length; i++)
            ans = Math.min(ans, solve(0, i));
        return ans;
    }
    
    public int solve(int row, int col) {
        if (row == mat.length)
            return 0;
        if (col < 0 || col >= mat.length)
            return 10000000;
        if (dp[row][col] != 1000000000)
            return dp[row][col];
        dp[row][col] = mat[row][col] + Math.min(solve(row + 1, col), Math.min(solve(row + 1, col + 1), solve(row + 1, col - 1)));
        return dp[row][col];
    }
}