class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        nums.push_back(1);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        solve(1, 0, nums, dp, n);
        vector<int> ans;
        build(1, 0, nums, dp, n, ans);
        return ans;
    }

    int solve(int idx, int prv, vector<int> &nums, vector<vector<int>> &dp, int &n) {
        if (idx == n)
            return 0;
        int &ret = dp[idx][prv];
        if (~ret)
            return ret;
        ret = 0;
        if (nums[idx] % nums[prv] == 0)
            ret = solve(idx + 1, idx, nums, dp, n) + 1;
        ret = max(ret, solve(idx + 1, prv, nums, dp, n));
        return ret;
    }

    void build(int idx, int prv, vector<int> &nums, vector<vector<int>> &dp, int &n, vector<int> &ans) {
        if (idx == n)
            return;
        int &ret = dp[idx][prv];
        if (nums[idx] % nums[prv] == 0 && ret == solve(idx + 1, idx, nums, dp, n) + 1) {
            ans.push_back(nums[idx]);
            build(idx + 1, idx, nums, dp, n, ans);
            return;
        }
        build(idx + 1, prv, nums, dp, n, ans);
    }
};
