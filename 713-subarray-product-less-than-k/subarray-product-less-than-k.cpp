class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if (k < 2)
            return 0;
        int left = 0, right = -1, ans = 0, curr = 1, sz = nums.size();
        while (++right < sz) {
            curr *= nums[right];
            while (left <= right && curr >= k)
                curr /= nums[left++];
            ans += right - left + 1;
        }
        return ans;
    }
};