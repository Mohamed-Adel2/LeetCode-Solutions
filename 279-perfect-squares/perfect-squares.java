class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, 100005);
        dp[0] = 0;
        for (int i = 1; i * i <= n; ++i) {
            for (int sum = 0; sum < n; ++sum) {
                int newSum = sum + (i * i);
                if (newSum <= n)
                    dp[newSum] = Math.min(dp[newSum], dp[sum] + 1);
            }
        }
        return dp[n];
    }
}