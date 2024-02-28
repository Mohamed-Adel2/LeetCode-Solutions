class Solution {
public:
    int val;
    int level = -1;

    int findBottomLeftValue(TreeNode *root) {
        solve(root, 0);
        return val;
    }

    void solve(TreeNode *node, int depth) {
        if (!node)
            return;
        if (depth > level){
            level = depth;
            val = node->val;
        }
        ++depth;
        solve(node->left, depth);
        solve(node->right, depth);
    }
};