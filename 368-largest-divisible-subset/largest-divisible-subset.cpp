class Solution {
public:
    vector<int> ans;
    vector<int> nums;
    vector<vector<int>> dp;
    int n;

    vector<int> largestDivisibleSubset(vector<int> &num) {
        this->nums = num;
        nums.push_back(1);
        sort(nums.begin(), nums.end());
        n = nums.size();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        solve(1, 0);
        build(1, 0);
        return ans;
    }

    int solve(int idx, int prv) {
        if (idx == n)
            return 0;
        int &ret = dp[idx][prv];
        if (~ret)
            return ret;
        ret = 0;
        if (nums[idx] % nums[prv] == 0)
            ret = solve(idx + 1, idx) + 1;
        ret = max(ret, solve(idx + 1, prv));
        return ret;
    }

    void build(int idx, int prv) {
        if (idx == n)
            return;
        int &ret = dp[idx][prv];
        if (nums[idx] % nums[prv] == 0 && ret == solve(idx + 1, idx) + 1) {
            ans.push_back(nums[idx]);
            build(idx + 1, idx);
            return;
        }
        build(idx + 1, prv);
    }
};
