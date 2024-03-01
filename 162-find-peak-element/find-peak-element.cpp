class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        if(nums.size() == 1)
            return 0;
        int lo = 1, hi = nums.size() - 2;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            if (nums[mid] > nums[mid - 1])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        if (nums[0] > nums[1])
            return 0;
        else if(nums[nums.size() - 1] > nums[nums.size() - 2])
            return nums.size() - 1;
        return 12345;
    }
};