class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ret;
        solve(ret, candidates, {}, 0, 0, target);
        return ret;
    }

    void solve(vector<vector<int>> &ret, vector<int> &candidates, vector<int> curr, int idx, int sum, int &target) {
        if (sum == target) {
            ret.push_back(curr);
            return;
        } else if (sum > target)
            return;
        for (int i = idx; i < candidates.size(); ++i) {
            curr.push_back(candidates[i]);
            solve(ret, candidates, curr, i, sum + candidates[i], target);
            curr.pop_back();
        }
    }
};