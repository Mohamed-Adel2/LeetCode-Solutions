class Solution {
public:
    TreeNode *ans;

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        solve(root, p, q);
        return ans;
    }

    int solve(TreeNode *node, TreeNode *p, TreeNode *q) {
        if (!node)
            return 0;
        int ret = (node == p || node == q);
        ret += solve(node->left, p, q) + solve(node->right, p, q);
        if (ret == 2) {
            ans = node;
            return 0;
        }
        return ret;
    }
};