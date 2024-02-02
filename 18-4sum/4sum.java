class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < nums.length - 3; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                for (int j = i + 1; j < nums.length - 2; j++) {
                    if (j == i + 1 || nums[j] != nums[j - 1]) {
                        int l = j + 1, r = nums.length - 1;
                        long needed = target - ((long)nums[i] + nums[j]);
                        while (l < r) {
                            if (nums[l] + nums[r] == needed) {
                                res.add(Arrays.asList(nums[l++], nums[r--], nums[i], nums[j]));
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
            }
        }
        return res;
    }
}