class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<bool> rows(n), cols(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!matrix[i][j])
                    rows[i] = cols[j] = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (rows[i] || cols[j])
                    matrix[i][j] = 0;
    }
};