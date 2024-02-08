class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int mnSz = Integer.MAX_VALUE, lo = 0, sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (sum >= target) {
                while (sum >= target)
                    sum -= nums[lo++];
                mnSz = Math.min(mnSz, i - lo + 2);
            }
        }
        return (mnSz == Integer.MAX_VALUE ? 0 : mnSz);
    }
}