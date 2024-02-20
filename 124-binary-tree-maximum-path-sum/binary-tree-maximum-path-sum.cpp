class Solution {
public:
    int ans = INT32_MIN;

    int maxPathSum(TreeNode *root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode *root) {
        int sum = root->val;
        ans = max(sum, ans);
        if (!root->left && !root->right)
            return sum;
        int left = 0, right = 0;
        if (root->left)
            left = max(0, dfs(root->left));
        if (root->right)
            right = max(0, dfs(root->right));
        ans = max(sum + left + right, ans);
        return max(sum + left, sum + right);
    }
};