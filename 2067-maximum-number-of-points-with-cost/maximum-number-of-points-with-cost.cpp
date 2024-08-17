class Solution {
public:
    long long maxPoints(vector<vector<int>> &points) {
        int n = points.size(), m = points[0].size();
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(m + 1, vector<long long>(4, -1)));
        return solve(0, 0, n, m, 0, dp, points);
    }

    long long
    solve(int row, int col, int n, int m, int dir, vector<vector<vector<long long>>> &dp, vector<vector<int>> &points) {
        if (row >= n || col >= m || row < 0 || col < 0)
            return 0;
        if (~dp[row][col][dir])
            return dp[row][col][dir];
        long long ret = solve(row + 1, col, n, m, 0, dp, points) + points[row][col];
        if (dir != 1)
            ret = max(ret, solve(row, col - 1, n, m, 2, dp, points) - (row ? 1 : 0));
        if (dir != 2)
            ret = max(ret, solve(row, col + 1, n, m, 1, dp, points) - (row ? 1 : 0));
        return dp[row][col][dir] = ret;
    }
};