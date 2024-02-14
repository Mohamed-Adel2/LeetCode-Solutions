class Solution {

    public List<List<Integer>> findMatrix(int[] nums) {
        Arrays.sort(nums);
        int mxCount = 1;
        for (int i = 1; i < nums.length; i++) {
            int curr = 1;
            while (i < nums.length && nums[i] == nums[i - 1]) {
                ++curr;
                ++i;
            }
            mxCount = Math.max(mxCount, curr);
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < mxCount; i++)
            ans.add(new ArrayList<>());
        int curr = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i == 0 || nums[i] != nums[i - 1])
                curr = 0;
            ans.get(curr).add(nums[i]);
            ++curr;
        }
        return ans;
    }
}