class Solution {
public:
    vector<int> ans;

    vector<int> rightSideView(TreeNode *root) {
        solve(root, 1);
        return ans;
    }

    void solve(TreeNode *node, int level) {
        if (!node)
            return;
        if (ans.size() < level)
            ans.emplace_back(node->val);
        solve(node->right, level + 1);
        solve(node->left, level + 1);
    }
};