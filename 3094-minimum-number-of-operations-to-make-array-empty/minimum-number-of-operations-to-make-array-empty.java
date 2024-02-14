class Solution {
    public int minOperations(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int i = 0; i < nums.length; i++)
            freq.put(nums[i], freq.getOrDefault(nums[i], 0) + 1);
        int ans = 0;
        for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
            int key = entry.getKey();
            int value = entry.getValue();
            if (value % 3 == 0)
                ans += value / 3;
            else if (value % 3 == 2)
                ans += value / 3 + 1;
            else if (value % 3 == 1 && value > 1)
                ans += value / 3 + 1;
            else
                return -1;
        }
        return ans;
    }
}