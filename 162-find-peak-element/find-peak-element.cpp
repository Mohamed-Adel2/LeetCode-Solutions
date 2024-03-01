class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            long prv = (mid == 0 ? INT64_MIN : nums[mid - 1]);
            long nxt = (mid == nums.size() - 1 ? INT64_MIN : nums[mid + 1]);
            if (nums[mid] > prv && nums[mid] > nxt)
                return mid;
            if (nums[mid] > prv)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return -12394;
    }
};