class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 1) {
                continue;
            }
            if (nums[nums[i] - 1] == -1) {
                ans.push_back(nums[i]);
                nums[nums[i] - 1] = -2;
            } else {
                int tmp = nums[i] - 1;
                swap(nums[i], nums[nums[i] - 1]);
                nums[tmp] = -1;
                --i;
            }
        }
        return ans;
    }
};