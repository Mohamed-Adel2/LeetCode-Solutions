class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(0, 0, m, n, dp);
    }

    int solve(int r, int c, int n, int m, vector<vector<int>>& dp){
        if(r == n - 1 && c == m - 1)
            return 1;
        if(r >= n || c >= m)
            return 0;
        int& ret = dp[r][c];
        if(~ret)
            return ret;
        ret = solve(r + 1, c, n, m, dp) + solve(r, c + 1, n, m, dp);
        return ret;
    }
};