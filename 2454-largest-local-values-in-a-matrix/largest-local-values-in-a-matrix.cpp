class Solution {
public:
    vector<int> dx{0, 0, 0, -1, -1, -1, 1, 1, 1}, dy{0, 1, -1, 1, 0, -1, -1, 0, 1};
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        for(int i = 0; i < n - 2; ++i)
            for(int j = 0; j < n - 2; ++j)
                ans[i][j] = getMax(i+1, j+1, grid);
        return ans;
    }

    int getMax(int row, int col, vector<vector<int>>& grid){
        int ret= 0;
        for(int i = 0; i < 9; ++i)
            ret = max(ret, grid[row + dx[i]][col + dy[i]]);
        return ret;
    }
};