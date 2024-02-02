class Solution {
    public int[] findErrorNums(int[] nums) {
        HashMap<Integer, Boolean> mp = new HashMap<>();
        int ans[] = new int[2];
        for (int i = 0; i < nums.length; i++) {
            if (mp.containsKey(nums[i]))
                ans[0] = nums[i];
            else {
                mp.put(nums[i], true);
            }
        }
        for (int i = 1; i <= nums.length; i++)
            if (!mp.containsKey(i))
                ans[1] = i;
        return ans;
    }
}