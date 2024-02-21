class Solution {
public:
    vector<int> ans;

    vector<int> rightSideView(TreeNode *root) {
        if (root)
            solve(root, 1);
        return ans;
    }

    void solve(TreeNode *node, int level) {
        if (ans.size() < level)
            ans.emplace_back(node->val);
        if (node->right)
            solve(node->right, level + 1);
        if (node->left)
            solve(node->left, level + 1);
    }
};