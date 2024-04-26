class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        int ans = 1e9;
        for(int i = 0; i<n;++i)
            ans = min(ans, solve(0, i, grid));
        return ans;
    }

    int solve(int r, int c, vector<vector<int>>& grid){
        if(r == n)
            return 0;
        int &ret = dp[r][c];
        if(~ret)
            return ret;
        ret = grid[r][c];
        int ans = 1e9;
        for(int i = 0;i < n;++i){
            if(i == c)
                continue;
            ans = min(ans ,solve(r + 1, i, grid));
        }
        ret += (ans == 1e9 ? 0 : ans);
        return ret;
    }

};