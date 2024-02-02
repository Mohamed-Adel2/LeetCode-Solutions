class Solution {
        public boolean canJump(int[] nums) {
        int end = 0, furthest = 0, ans = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            if(i > furthest)
                return false;
            furthest = Math.max(furthest, i + nums[i]);
            if (i == end) {
                end = furthest;
                ++ans;
            }
        }
        return furthest >= nums.length - 1;
    }
}