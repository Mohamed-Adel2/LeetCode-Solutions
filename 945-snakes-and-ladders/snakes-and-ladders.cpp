class Solution {
public:

    int snakesAndLadders(vector<vector<int>> &board) {
        vector<int> flattenedBoard;
        int n = board.size();
        bool keep = true;
        for (int i = n - 1; i >= 0; --i) {
            int start = (!keep ? n - 1 : 0), end = (!keep ? -1 : n), step = (!keep ? -1 : 1);
            for (int j = start; j != end; j += step)
                flattenedBoard.push_back(board[i][j]);
            keep ^= 1;
        }
        return bfs(n, flattenedBoard);
    }

    int bfs(int n, vector<int> &board) {
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<bool> vis(n * n);
        while (!q.empty()) {
            int idx = q.front().first, dist = q.front().second;
            q.pop();
            if (idx == n * n - 1)
                return dist;
            for (int i = 1; i <= 6; ++i)
                if (idx + i < n * n) {
                    int nxtIdx = (~board[idx + i] ? board[idx + i] - 1 : idx + i);
                    if (!vis[nxtIdx])
                        q.push({nxtIdx, dist + 1}), vis[nxtIdx] = true;
                }
        }
        return -1;
    }
};