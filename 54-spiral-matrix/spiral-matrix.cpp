class Solution {
public:
    int n, m, dx, dy, currX, currY;
    char dir;

    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        dir = 'R';
        dx = 0, dy = 1, currX = 0, currY = -1, n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        vector<int> ans;
        for (int i = 0; i < n * m; ++i) {
            if (!valid(vis, currX + dx, currY + dy))
                changeDir();
            currX += dx, currY += dy;
            vis[currX][currY] = true;
            ans.push_back(matrix[currX][currY]);
        }
        return ans;
    }

    bool valid(vector<vector<int>> &vis, int row, int col) {
        return (row >= 0 && row < n && col >= 0 && col < m && !vis[row][col]);
    }

    void changeDir() {
        if (dir == 'R')
            dir = 'D', dx = 1, dy = 0;
        else if (dir == 'D')
            dir = 'L', dx = 0, dy = -1;
        else if (dir == 'L')
            dir = 'U', dx = -1, dy = 0;
        else
            dir = 'R', dx = 0, dy = 1;
    }
};