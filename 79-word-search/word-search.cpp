class Solution {
public:
    int n, m;
    vector<int> dx, dy;

    bool exist(vector<vector<char>> &board, string word) {
        bool exist = false;
        n = board.size(), m = board[0].size();
        dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (board[row][col] != word[0])
                    continue;
                char ch = board[row][col];
                board[row][col] = '-';
                solve(board, exist, word, 1, row, col);
                board[row][col] = ch;
                if (exist)
                    return true;
            }
        }
        return false;
    }

    void solve(vector<vector<char>> &board, bool &exist, string &word, int idx, int row, int col) {
        if (idx == word.size())
            return void(exist = true);
        for (int i = 0; i < 4; ++i) {
            int newRow = row + dx[i], newCol = col + dy[i];
            if (valid(newRow, newCol) && board[newRow][newCol] == word[idx]) {
                char ch = board[newRow][newCol];
                board[newRow][newCol] = '-';
                solve(board, exist, word, idx + 1, newRow, newCol);
                board[newRow][newCol] = ch;
                if (exist)
                    return;
            }
        }
    }

    bool valid(int row, int col) {
        return !(row < 0 || row >= n || col < 0 || col >= m);
    }
};