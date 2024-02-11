class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;
    vector<int> dy;
    vector<vector<int>> grid;

    int cherryPickup(vector<vector<int>> &g) {
        grid = g;
        n = grid.size(), m = grid[0].size();
        dp.resize(n + 2, vector<vector<int>>(m + 2, vector<int>(m + 2, -1)));
        dy = {-1, 0, 1};
        return grid[0][0] + grid[0][m - 1] + solve(0, 0, m - 1);
    }

    int solve(int r, int c1, int c2) {
        if (r == n - 1)
            return 0;
        int &ret = dp[r][c1][c2];
        if (~ret)
            return ret;
        ret = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                int newr = r + 1, newc1 = c1 + dy[i], newc2 = c2 + dy[j];
                if (valid(newc1, newc2))
                    ret = max(ret,
                              solve(newr, newc1, newc2) + grid[newr][newc1] + (newc1 == newc2 ? 0 : grid[newr][newc2]));
            }
        return ret;
    }

    bool valid(int x, int y) {
        return (x >= 0 && x < m && y >= 0 && y < m);
    }
};