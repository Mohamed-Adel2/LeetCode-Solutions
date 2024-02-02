class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] == 0) {
                int j = i - 1;
                while (j >= 0 && nums[j] <= i - j)
                    --j;
                if (j == -1)
                    return false;
                i = j;
            }
        }
        return true;
    }
}