class Solution {
public:
    int ans = 0;

    int longestZigZag(TreeNode *root) {
        int left = solve(root->left, false), right = solve(root->right, true);
        return max({ans, left, right});
    }

    int solve(TreeNode *node, bool left) {
        if (!node)
            return 0;
        if (left) {
            ans = max(ans, solve(node->right, true));
            return 1 + solve(node->left, false);
        } else {
            ans = max(ans, solve(node->left, false));
            return 1 + solve(node->right, true);
        }
    }
};