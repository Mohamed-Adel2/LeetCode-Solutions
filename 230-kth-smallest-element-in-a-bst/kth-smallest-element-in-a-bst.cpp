class Solution {
public:
    int ans = 0;

    int kthSmallest(TreeNode *root, int k) {
        dfs(root, k);
        return ans;
    }

    void dfs(TreeNode *node, int &k) {
        if (!node)
            return;
        dfs(node->left, k);
        --k;
        if (k == 0)
        ans = node->val;
        dfs(node->right, k);

    }
};