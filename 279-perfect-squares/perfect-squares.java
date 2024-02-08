class Solution {
    public int numSquares(int n) {
        ArrayList<Integer> prefects = new ArrayList<>();
        for (int i = 1; i * i <= n; i++)
            prefects.add(i * i);
        int[] dp = new int[n + 1];
        for (int i = 0; i <= n; i++)
            dp[i] = 100000;
        dp[0] = 0;
        for (int i = 0; i < prefects.size(); i++) {
            for (int sum = 0; sum < n; sum++) {
                int newSum = sum + prefects.get(i);
                if (newSum <= n)
                    dp[newSum] = Math.min(dp[newSum], dp[sum] + 1);
            }
        }
        return dp[n];
    }
}