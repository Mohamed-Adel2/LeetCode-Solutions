class Solution {
    public int maxVowels(String s, int k) {
        int[] nums = new int[s.length()];
        Set<Character> vowels = new HashSet<>(Arrays.asList('a', 'i', 'o', 'e', 'u'));
        nums[0] = (vowels.contains(s.charAt(0)) ? 1 : 0);
        for (int i = 1; i < nums.length; i++)
            nums[i] = nums[i - 1] + (vowels.contains(s.charAt(i)) ? 1 : 0);
        int ans = nums[k - 1];
        for (int i = 1; i <= nums.length - k; i++)
            ans = Math.max(ans, nums[k + i - 1] - nums[i - 1]);
        return ans;
    }
}