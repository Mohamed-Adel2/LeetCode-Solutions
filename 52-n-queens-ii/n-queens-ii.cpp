class Solution {
public:
    int ans = 0;

    int totalNQueens(int n) {
        vector<bool> col(n), diag1(2 * n), diag2(2 * n);
        solve(n, n, 0, col, diag1, diag2);
        return ans;
    }

    void solve(int done, int n, int row, vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2) {
        if (done == 0)
            return void(++ans);
        for (int i = 0; i < col.size(); ++i) {
            if (!col[i] && !diag1[row + i] && !diag2[row - i + n]) {
                col[i] = diag1[row + i] = diag2[row - i + n] = true;
                solve(done - 1, n, row + 1, col, diag1, diag2);
                col[i] = diag1[row + i] = diag2[row - i + n] = false;
            }
        }
    }
};