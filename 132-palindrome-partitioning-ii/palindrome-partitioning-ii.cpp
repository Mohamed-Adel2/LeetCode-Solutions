class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> p(n + 1, vector<bool>(n + 1, false));
        for(int i = n - 1; i >= 0; --i)
            for(int j = i; j < n; ++j)
                p[i][j] = (i + 1 >= n || j - 1 < 0 || i + 1 > j - 1? true : p[i + 1][j - 1]) & (s[i] == s[j]);
        if(p[0][n-1])
            return 0;
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return solve(0, 0, n, p, dp) - 1;
    }
    int solve(int idx, int start, int n, vector<vector<bool>>& p, vector<vector<int>>& dp){
        if(idx == n && start == idx)
            return 0;
        if(idx == n && start != idx)
            return 10000;
        int& ret = dp[idx][start];
        if(~ret)
            return ret;
        ret = solve(idx + 1, start, n, p, dp);
        if(p[start][idx])
            ret = min(ret, solve(idx + 1, idx + 1, n, p, dp) + 1);
        return ret;
    }
};