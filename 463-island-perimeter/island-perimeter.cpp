class Solution {
public:
    int ans = 0, n, m;
    vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for(int i = 0;i<grid.size();++i)
            for(int j = 0;j<grid[0].size();++j)
                if(grid[i][j] == 1){
                    solve(i, j, grid);
                    return ans;
                }
        return -18405215;
    }
    void solve(int row, int col, vector<vector<int>>& grid){
        ans += 4;
        grid[row][col] = -1;
        for(int i = 0;i<4;++i){
            int newX = row + dx[i], newY = col + dy[i];
            if(valid(newX, newY)){
                if(grid[newX][newY] == 1)
                    solve(row+dx[i], col+dy[i], grid), ans-=1;
                else if(grid[newX][newY] == -1)
                    ans-=1; 
            }
        }
    }
    bool valid(int row, int col){
        return(row >= 0 && row < n && col >= 0 && col < m);
    }
};