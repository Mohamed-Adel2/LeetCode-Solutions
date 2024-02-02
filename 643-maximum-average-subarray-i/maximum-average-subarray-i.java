class Solution {
    public double findMaxAverage(int[] nums, int k) {
        for (int i = 1; i < nums.length; i++)
            nums[i] += nums[i - 1];
        double ans = (double) nums[k - 1] / k;
        for (int i = 1; i <= nums.length - k; i++)
            ans = Math.max(ans, ((double) nums[k + i - 1] - nums[i - 1]) / k);
        return ans;
    }
}