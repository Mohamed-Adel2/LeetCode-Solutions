class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> ones(rows, vector<int>(cols));
        for (int i = 0; i < rows; ++i) {
            int next = cols;
            for (int j = cols - 1; j >= 0; --j) {
                if (matrix[i][j] == '1')
                    ones[i][j] = next - j;
                else
                    next = j;
            }
        }
        int ans = 0;
        for (int j = 0; j < cols; ++j) {
            for (int start = 0; start < rows; ++start) {
                int mx = 1000;
                for (int i = start; i < rows; ++i) {
                    if (matrix[i][j] == '0')
                        break;
                    mx = min(mx, ones[i][j]);
                    ans = max(ans, mx * (i - start + 1));
                }
            }
        }
        return ans;
    }
};