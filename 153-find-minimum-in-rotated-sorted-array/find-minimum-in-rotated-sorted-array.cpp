class Solution {
public:
    int findMin(vector<int> &nums) {
        int sz = nums.size();
        int lo = 0, hi = sz - 1;
        int ans = nums[lo];
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] < nums[(mid + 1) % sz] && nums[mid] < nums[(mid - 1 + sz) % sz]) {
                ans = nums[mid];
                break;
            } else if (nums[mid] < nums[sz - 1]) {
                hi = mid - 1;
            } else
                lo = mid + 1;
        }
        return ans;
    }
};