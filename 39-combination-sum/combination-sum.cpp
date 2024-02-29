class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ret;
        vector<int> curr;
        solve(ret, candidates, curr, 0, target);
        return ret;
    }

    void solve(vector<vector<int>> &ret, vector<int> &candidates, vector<int>& curr, int idx, int sum) {
        if (sum == 0) {
            ret.push_back(curr);
            return;
        } else if (sum < 0)
            return;
        for (int i = idx; i < candidates.size(); ++i) {
            curr.push_back(candidates[i]);
            solve(ret, candidates, curr, i, sum - candidates[i]);
            curr.pop_back();
        }
    }
};