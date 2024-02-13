class Solution {
public:
    int n, m;

    void gameOfLife(vector<vector<int>> &board) {
        int dx[] = {0, 0, 1, -1, -1, 1, -1, 1};
        int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int liveNeighbors = countLiveNeighbors(board, i, j, dx, dy);
                if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3))
                    board[i][j] = 2;
                else if (board[i][j] == 0 && liveNeighbors == 3)
                    board[i][j] = -1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 2)
                    board[i][j] = 0;
                else if (board[i][j] == -1)
                    board[i][j] = 1;
            }
        }
    }

    int countLiveNeighbors(vector<vector<int>> &board, int row, int col, int dx[], int dy[]) {
        int count = 0;
        for (int i = 0; i < 8; ++i) {
            int newX = row + dx[i], newY = col + dy[i];
            if (valid(newX, newY) && (board[newX][newY] == 1 || board[newX][newY] == 2))
                ++count;
        }
        return count;
    }

    bool valid(int row, int col) {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
};