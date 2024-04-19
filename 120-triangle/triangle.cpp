class Solution {
public:
    vector<vector<int>> dp;
    int n, m;

    int minimumTotal(vector<vector<int>> &triangle) {
        n = triangle.size(), m = triangle[0].size();
        dp.resize(n + 2);
        for(int i = 0;i<n+2;++i)
            dp[i].resize(i+2, 1e9);
        return solve(0, 0, triangle);
    }

    int solve(int row, int col, vector<vector<int>> &triangle) {
        if (row >= n)
            return 0;
        int &ret = dp[row][col];
        if (ret != 1e9)
            return ret;
        ret = min(solve(row + 1, col, triangle), solve(row + 1, col + 1, triangle)) + triangle[row][col];
        return ret;
    }
};
