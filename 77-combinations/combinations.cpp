class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> state;
        solve(ret, state, 0, 0, k, n);
        return ret;
    }

    void solve(vector<vector<int>> &ret, vector<int> &curr, int idx, int last, int &k, int &n) {
        if (idx == k) {
            ret.push_back(curr);
            return;
        }
        for (int i = last + 1; i <= n; ++i) {
            curr.push_back(i);
            solve(ret, curr, idx + 1, i, k, n);
            curr.pop_back();
        }
    }
};