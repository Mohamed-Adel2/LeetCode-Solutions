class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n - 2; ++i)
            for(int j = 0; j < m - 2; ++j)
                if(valid(grid, i, j))
                    ++ans;
        return ans;
    }

    bool valid(vector<vector<int>>& grid, int row, int col){
        vector<int> st;
        for(int i = row; i < row + 3; ++i)
            for(int j = col; j < col + 3; ++j)
                st.push_back(grid[i][j]);
        sort(st.begin(), st.end());
        for(int i = 1; i < 9; ++i)
            if(st[i] - 1 != st[i - 1])
                return false;
        if(st[0] != 1)
            return false;
        int row1 = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        int row2 = grid[row+1][col] + grid[row+1][col+1] + grid[row+1][col+2];
        int row3 = grid[row+2][col] + grid[row+2][col+1] + grid[row+2][col+2];
        int col1 = grid[row][col] + grid[row+1][col] + grid[row+2][col];
        int col2 = grid[row][col+1] + grid[row+1][col+1] + grid[row+2][col+1];
        int col3 = grid[row][col+2] + grid[row+1][col+2] + grid[row+2][col+2];
        int diag1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int diag2 = grid[row][col+2] + grid[row + 1][col + 1] + grid[row + 2][col];
        int val = row1 & row2 & row3 & col1 & col2 & col3 & diag1 & diag2;
        if(val == row1 && val == diag2)
            return true;
        return false;
    }
};