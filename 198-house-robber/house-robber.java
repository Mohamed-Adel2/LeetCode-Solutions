class Solution {
    int dp[];

    public int rob(int[] nums) {
        dp = new int[nums.length];
        for(int i = 0;i < nums.length;i++)
            dp[i] = -1;
        return solve(0, nums.length, nums);
    }

    public int solve(int idx, int n, int[] nums) {
        if (idx >= n)
            return 0;
        int ret = dp[idx];
        if (ret != -1)
            return ret;
        ret = Math.max(nums[idx] + solve(idx + 2, n, nums), solve(idx + 1,n ,nums));
        return dp[idx] = ret;
    }
}