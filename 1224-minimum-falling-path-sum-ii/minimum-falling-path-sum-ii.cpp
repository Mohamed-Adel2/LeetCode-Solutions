class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &grid) {
        int n = grid.size();
        if (n == 1)
            return grid[0][0];
        for (int i = 0; i < n - 1; ++i) {
            int firstMn, secondMn;
            if (grid[i][0] < grid[i][1])
                firstMn = 0, secondMn = 1;
            else
                firstMn = 1, secondMn = 0;
            for (int j = 2; j < n; ++j) {
                if (grid[i][j] <= grid[i][firstMn])
                    secondMn = firstMn, firstMn = j;
                else if (grid[i][j] < grid[i][secondMn])
                    secondMn = j;
            }
            for (int j = 0; j < n; ++j) {
                if (j == firstMn)
                    grid[i + 1][j] += grid[i][secondMn];
                else
                    grid[i + 1][j] += grid[i][firstMn];
            }
        }
        int ans = 1e6;
        for (int j = 0; j < n; ++j)
            ans = min(grid[n - 1][j], ans);
        return ans;
    }
};
