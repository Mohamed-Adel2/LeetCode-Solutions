class Solution {
public:
    vector<vector<char>> board;
    vector<vector<bool>> vis;
    int n, m;
    vector<int> dx, dy;

    bool exist(vector<vector<char>> &b, string word) {
        board = b;
        bool exist = false;
        n = b.size(), m = b[0].size();
        dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
        string curr;
        vis.resize(n, vector<bool>(m));
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                vis[row][col] = true;
                curr.push_back(board[row][col]);
                solve(exist, word, curr, word.size() - 1, row, col);
                vis[row][col] = false;
                curr.pop_back();
                if (exist)
                    return true;
            }
        }
        return false;
    }

    void solve(bool &exist, string &word, string &curr, int sz, int row, int col) {
        if (sz == 0) {
            exist |= (word == curr);
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int newRow = row + dx[i], newCol = col + dy[i];
            if (valid(newRow, newCol)) {
                curr.push_back(board[newRow][newCol]);
                vis[newRow][newCol] = true;
                solve(exist, word, curr, sz - 1, newRow, newCol);
                vis[newRow][newCol] = false;
                curr.pop_back();
                if(exist)
                    return;
            }
        }
    }

    bool valid(int row, int col) {
        return (row >= 0 && row < n && col >= 0 && col < m && !vis[row][col]);
    }
};