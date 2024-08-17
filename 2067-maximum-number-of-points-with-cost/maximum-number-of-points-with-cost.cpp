class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, -1));
        return solve(0, 0, n, m, dp, points);
    }

    long long solve(int row, int col, int n, int m, vector<vector<long long>>& dp, vector<vector<int>>& points){
        if(row >= n || col >= m || row < 0 || col < 0)
            return 0;
        long long& ret = dp[row][col];
        if(~ret)
            return ret;
        ret = solve(row + 1, col, n, m, dp, points) + points[row][col];
        ret = max(ret, solve(row, col - 1, n , m, dp, points) - (row ? 1 : 0));
        ret = max(ret, solve(row, col + 1, n , m, dp, points) - (row ? 1 : 0));
        return ret;
    }

};