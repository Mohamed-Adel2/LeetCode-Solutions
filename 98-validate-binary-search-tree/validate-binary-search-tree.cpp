class Solution {
public:
    bool valid = true, first = true;
    int last;

    bool isValidBST(TreeNode *root) {
        dfs(root);
        return valid;
    }

    void dfs(TreeNode *node) {
        if (!valid || !node)
            return;
        dfs(node->left);
        if (!first && node->val <= last) {
            valid = false;
            return;
        } else {
            last = node->val;
            first = false;
        }
        dfs(node->right);
    }
};