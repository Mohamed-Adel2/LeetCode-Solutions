class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(ans, curr, nums, 0);
        return ans;
    }

    void solve(vector<vector<int>> &ans, vector<int> &curr, vector<int> &nums, int idx) {
        if (idx == nums.size())
            return void(ans.emplace_back(curr));
        solve(ans, curr, nums, idx + 1);
        curr.emplace_back(nums[idx]);
        solve(ans, curr, nums, idx + 1);
        curr.pop_back();
    }
};