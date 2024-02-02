class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (freq.containsKey(target - nums[i]) && freq.get(target - nums[i]) != i) {
                return new int[]{i, freq.get(target - nums[i])};
            }
            else
                freq.put(nums[i], i);
        }
        return nums;
    }
}