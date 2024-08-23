class Solution {
public:
    Node *construct(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<vector<int>> prefix(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                prefix[i + 1][j + 1] = prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j] + grid[i][j];
        return solve(prefix, 1, 1, n, n);
    }

    Node *solve(vector<vector<int>> &prefix, int r1, int c1, int r2, int c2) {
        int sum = getRange(prefix, r1, c1, r2, c2);
        if (sum == 0 || sum == (r2 - r1 + 1) * (r2 - r1 + 1))
            return new Node(sum != 0, true);
        Node *node = new Node(false, false);
        int sz = (r2 - r1 + 1) / 2;
        node->topLeft = solve(prefix, r1, c1, r1 + sz - 1, c1 + sz - 1);
        node->topRight = solve(prefix, r1, c1 + sz, r1 + sz - 1, c2);
        node->bottomLeft = solve(prefix, r1 + sz, c1, r2, c1 + sz - 1);
        node->bottomRight = solve(prefix, r1 + sz, c1 + sz, r2, c2);
        return node;
    }

    int getRange(vector<vector<int>> &prefix, int r1, int c1, int r2, int c2) {
        return prefix[r2][c2] + prefix[r1 - 1][c1 - 1] - prefix[r2][c1 - 1] - prefix[r1 - 1][c2];
    }
};