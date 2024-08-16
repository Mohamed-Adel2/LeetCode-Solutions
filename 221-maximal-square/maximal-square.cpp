class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<char>>& matrix, vector<vector<int>>& dp){
        if(i >=n || j >= m)
            return 0;
        int& ret = dp[i][j];
        if(~ret)
            return ret;
        if(matrix[i][j] == '0')
            return ret = 0;
        ret = 1 + min({solve(i + 1, j, n, m, matrix, dp), solve(i, j + 1, n, m, matrix, dp), solve(i + 1, j + 1, n, m, matrix, dp)});
        return ret;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                ans = max(ans, solve(i, j, n, m, matrix, dp));
        return ans * ans;
    }
};