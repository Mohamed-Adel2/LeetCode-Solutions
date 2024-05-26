class Solution {
public:
    vector<vector<vector<int>>> dp;

    int checkRecord(int n) {
        dp.resize(n + 2, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, false, 0, n);
    }

    int solve(int idx, bool absent, int late, int n) {
        if (idx >= n)
            return 1;
        int &ret = dp[idx][absent][late];
        if (~ret)
            return ret;
        ret = 0;
        if (!absent)
            ret = solve(idx + 1, !absent, 0, n);
        if (late < 2)
            ret = (ret + solve(idx + 1, absent, late + 1, n)) % 1000000007;
        ret = (ret + solve(idx + 1, absent, 0, n)) % 1000000007;
        return ret;
    }
};