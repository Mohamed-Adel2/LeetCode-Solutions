class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; ++i){
            if(grid[i][0] == 0)
                for(int j = 0; j < m;++j)
                    grid[i][j] ^= 1;
        }
        int ans = (1 << m) * n;
        for(int j = 1; j < m;++j){
            int cnt = 0;
            for(int i = 0; i < n;++i)
                cnt += (grid[i][j] == 1);
            cnt = max(cnt, n - cnt);
            ans += (1 << (m - j)) * cnt;
        }
        return ans / 2;
    }
};