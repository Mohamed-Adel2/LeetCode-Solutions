class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int lo = 0, hi = n * m - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (matrix[mid / m][mid % m] < target)
                lo = mid + 1;
            else if (matrix[mid / m][mid % m] > target)
                hi = mid - 1;
            else
                return true;
        }
        return false;
    }
};