class Solution {
public:
    int n, m;
    vector<int> dx, dy;

    bool exist(vector<vector<char>> &board, string word) {
        bool exist = false;
        n = board.size(), m = board[0].size();
        dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
        string curr;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                char ch = board[row][col];
                curr.push_back(board[row][col]);
                board[row][col] = '-';
                solve(board, exist, word, curr, word.size() - 1, row, col);
                board[row][col] = ch;
                curr.pop_back();
                if (exist)
                    return true;
            }
        }
        return false;
    }

    void solve(vector<vector<char>> &board, bool &exist, string &word, string &curr, int sz, int row, int col) {
        if (sz == 0) {
            exist = (word == curr);
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int newRow = row + dx[i], newCol = col + dy[i];
            if (valid(newRow, newCol) && board[newRow][newCol] != '-') {
                curr.push_back(board[newRow][newCol]);
                char ch = board[newRow][newCol];
                board[newRow][newCol] = '-';
                solve(board, exist, word, curr, sz - 1, newRow, newCol);
                board[newRow][newCol] = ch;
                curr.pop_back();
                if (exist)
                    return;
            }
        }
    }

    bool valid(int row, int col) {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
};