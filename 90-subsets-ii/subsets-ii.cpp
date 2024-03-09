class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        solve(ans, curr, nums, 0);
        return ans;
    }

    void solve(vector<vector<int>> &ans, vector<int> &curr, vector<int> &nums,
               int idx) {
        if (idx >= nums.size())
            return void(ans.push_back(curr));
        solve(ans, curr, nums, idx + 1);
        int val = nums[idx];
        while (idx < nums.size() && nums[idx] == val)
            curr.emplace_back(nums[idx++]);
        solve(ans, curr, nums, idx);
        while (!curr.empty() && curr.back() == val)
            curr.pop_back();
    }
};