class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int ans = -1;
        while (lo <= hi) {
            int mid = (hi + lo) / 2;
            if (nums[mid] <= target) {
                ans = mid;
                lo = mid + 1;
            } else
                hi = mid - 1;
        }
        return ans + (nums[max(ans, 0)] != target);
    }
};