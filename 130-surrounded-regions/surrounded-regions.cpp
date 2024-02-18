class Solution {
public:
    vector<vector<bool>> vis;
    int n, m;
    vector<int> dx, dy;
    vector<vector<char>> board;

    void solve(vector<vector<char>> &b) {
        board = b;
        n = board.size(), m = board[0].size();
        vis.resize(n, vector<bool>(m, false));
        dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
        for (int i = 0; i < m; i++) {
            if (!vis[0][i] && board[0][i] == 'O')
                dfs(0, i);
            if (!vis[n - 1][i] && board[n - 1][i] == 'O')
                dfs(n - 1, i);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O')
                dfs(i, 0);
            if (!vis[i][m - 1] && board[i][m - 1] == 'O')
                dfs(i, m - 1);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (b[i][j] == 'O' && !vis[i][j])
                    b[i][j] = 'X';
    }

    void dfs(int row, int col) {
        vis[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int newX = row + dx[i], newY = col + dy[i];
            if (valid(newX, newY))
                dfs(newX, newY);
        }
    }

    bool valid(int row, int col) {
        return (row >= 0 && row < n && col >= 0 && col < m && !vis[row][col] && board[row][col] == 'O');
    }
};