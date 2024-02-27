class Solution {
public:
    int ans = 0;

    int diameterOfBinaryTree(TreeNode *root) {
        solve(root);
        return ans;
    }

    int solve(TreeNode *node) {
        if (node == NULL)
            return 0;
        int left = solve(node->left), right = solve(node->right);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
};