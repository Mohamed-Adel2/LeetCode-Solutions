class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int sum = 0, mnSz = 0, l = 0, r = 0, n = nums.length;
        while (r < n && sum < target)
            sum += nums[r++];
        if (sum < target)
            return 0;
        mnSz = r;
        while (r <= n) {
            if (sum >= target) {
                mnSz = Math.min(mnSz, r - l);
                sum -= nums[l++];
            } else {
                if (r == n)
                    break;
                sum += nums[r++];
            }
        }
        return mnSz;
    }
}