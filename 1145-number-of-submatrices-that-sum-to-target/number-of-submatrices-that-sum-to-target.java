class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;
        int[][] sum = new int[n + 1][m + 1];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                Map<Integer, Integer> freq = new HashMap<>();
                freq.put(0, 1);
                int currSum = 0;
                for (int k = 1; k <= m; k++) {
                    currSum = sum[j][k] - sum[i - 1][k] - sum[j][0] + sum[i - 1][0];
                    if (freq.containsKey(currSum - target))
                        ans += freq.get(currSum - target);
                    freq.put(currSum, freq.getOrDefault(currSum, 0) + 1);
                }
            }
        }
        return ans;
    }
}