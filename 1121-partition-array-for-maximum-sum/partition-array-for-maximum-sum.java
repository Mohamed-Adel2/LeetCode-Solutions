class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] dp = new int[n + 1];
        for (int i = n - 1; i >= 0; --i) {
            int currMax = arr[i];
            for (int j = 1; i + j <= n && j <= k; ++j) {
                dp[i] = Math.max(dp[i], currMax * j + dp[i + j]);
                if (i + j < n)
                    currMax = Math.max(currMax, arr[i + j]);
            }
        }
        return dp[0];
    }
}