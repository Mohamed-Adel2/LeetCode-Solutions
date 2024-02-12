class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[][] col = new boolean[9][10];
        boolean[][] row = new boolean[9][10];
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                if (col[i][board[i][j] - '0'] || row[j][board[i][j] - '0'])
                    return false;
                col[i][board[i][j] - '0'] = true;
                row[j][board[i][j] - '0'] = true;
            }
        for (int i = 0; i < 9; i += 3)
            for (int j = 0; j < 9; j += 3)
                if (!validateSubGrid(board, i, j))
                    return false;
        return true;
    }

    public boolean validateSubGrid(char[][] board, int row, int col) {
        boolean[] vis = new boolean[10];
        for (int i = row; i < row + 3; i++)
            for (int j = col; j < col + 3; j++) {
                if (board[i][j] == '.')
                    continue;
                if (vis[board[i][j] - '0'])
                    return false;
                vis[board[i][j] - '0'] = true;
            }
        return true;
    }
}