class Solution {
public:
    int n, m;
    vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        n = land.size(), m = land[0].size();
        for(int i = 0;i<n;++i){
            for(int j = 0;j<m;++j){
                if(land[i][j] == 1){
                    int mxRow = i, mxCol = j;
                    dfs(i, j, mxRow, mxCol, land);
                    ans.push_back({i, j, mxRow, mxCol});
                } 
            }
        }
        return ans;
    }

    void dfs(int row, int col, int& mxRow, int& mxCol, vector<vector<int>>& land){
        land[row][col] = 0;
        for(int i = 0;i<4;++i){
            int newRow = row + dx[i], newCol = col + dy[i];
            if(valid(newRow, newCol) && land[newRow][newCol] == 1){
                mxRow = max(mxRow, newRow), mxCol = max(mxCol, newCol);
                dfs(newRow, newCol, mxRow, mxCol, land);
            }
        }
    }

    bool valid(int row, int col){
        return(row >= 0 && row < n && col >= 0 && col < m);
    }
};