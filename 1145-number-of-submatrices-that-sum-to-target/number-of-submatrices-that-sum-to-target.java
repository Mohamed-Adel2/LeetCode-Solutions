class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;
        int[][] sum = new int[n + 1][m + 1];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                sum[i][j] = sum[i][j - 1] + matrix[i - 1][j - 1];
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                sum[j][i] += sum[j - 1][i];


        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                for (int k = 1; k <= m; k++) {
                    for (int l = k; l <= m; l++) {
                        int tmp = sum[j][l] - sum[i - 1][l] - sum[j][k - 1] + sum[i - 1][k - 1];
                        if (tmp == target)
                            ++ans;
                    }
                }
            }
        }
        return ans;
    }
}