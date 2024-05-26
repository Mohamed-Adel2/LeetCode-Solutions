class Solution {
public:
    int dp[100005][2][3];
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
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