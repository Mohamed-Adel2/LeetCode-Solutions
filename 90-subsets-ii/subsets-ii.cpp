class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        set<vector<int>> ans;
        vector<int> curr;
        map<vector<int>, bool> vis;
        sort(nums.begin(), nums.end());
        solve(ans, curr, nums, 0);
        vector<vector<int>> ret;
        for(auto i : ans)
            ret.push_back(i);
        return ret;
    }

    void solve(set<vector<int>> &ans, vector<int> &curr, vector<int> &nums, int idx) {
        if (idx == nums.size())
            return void(ans.insert(curr));
        solve(ans, curr, nums, idx + 1);
        curr.emplace_back(nums[idx]);
        solve(ans, curr, nums, idx + 1);
        curr.pop_back();
    }
};