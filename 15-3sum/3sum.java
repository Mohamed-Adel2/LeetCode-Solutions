class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < nums.length - 2; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int l = i + 1, r = nums.length - 1, needed = -nums[i];
                while (l < r) {
                    if (nums[l] + nums[r] == needed) {
                        res.add(Arrays.asList(nums[l++], nums[r--], nums[i]));
                        while (l < r && nums[l] == nums[l - 1])
                            ++l;
                        while (r > l && nums[r] == nums[r + 1])
                            --r;
                    } else if (nums[l] + nums[r] > needed)
                        --r;
                    else
                        ++l;
                }
            }
        }
        return res;
    }
}