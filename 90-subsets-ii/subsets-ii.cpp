class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        map<vector<int>, bool> vis;
        sort(nums.begin(), nums.end());
        solve(ans, curr, nums, vis, 0);
        return ans;
    }

    void solve(vector<vector<int>> &ans, vector<int> &curr, vector<int> &nums, map<vector<int>, bool> &vis,
               int idx) {
        if (idx == nums.size()) {
            if (!vis[curr])
                ans.emplace_back(curr), vis[curr] = true;
            return;
        }
        solve(ans, curr, nums, vis, idx + 1);
        curr.emplace_back(nums[idx]);
        solve(ans, curr, nums, vis, idx + 1);
        curr.pop_back();
    }
};