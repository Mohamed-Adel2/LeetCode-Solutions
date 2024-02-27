class Solution {
public:
    int ans = 0;

    int diameterOfBinaryTree(TreeNode *root) {
        solve(root);
        return ans - 1;
    }

    int solve(TreeNode *node) {
        if (node == nullptr)
            return 0;
        int left = solve(node->left), right = solve(node->right);
        ans = max(ans, left + right + 1);
        return max(left, right) + 1;
    }
};