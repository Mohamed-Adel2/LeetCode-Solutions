class Solution {
public:
    int n, m;
    vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0;i<n;++i)
            for(int j = 0;j<m;++j)
                if(grid[i][j]){
                    for(int k = 0;k<4;++k)
                        if(!valid(i+dx[k], j+dy[k]) || !grid[i+dx[k]][j+dy[k]])
                            ++ans;

                }
        return ans;
    }

    bool valid(int row, int col){
        return(row >= 0 && row < n && col >= 0 && col < m);
    }
};