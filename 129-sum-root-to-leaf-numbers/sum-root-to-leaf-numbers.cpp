class Solution {
public:
    int totalSum = 0;

    int sumNumbers(TreeNode *root) {
        solve(root, 0);
        return totalSum;
    }

    void solve(TreeNode *node, int pathSum) {
        if (!node->right && !node->left)
            totalSum += (pathSum * 10) + node->val;
        if (node->right)
            solve(node->right, pathSum * 10 + node->val);
        if (node->left)
            solve(node->left, pathSum * 10 + node->val);
    }
};
