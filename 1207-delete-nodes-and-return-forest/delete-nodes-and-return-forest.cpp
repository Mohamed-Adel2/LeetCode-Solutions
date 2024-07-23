/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        vector<TreeNode *> ans;
        unordered_map<int, bool> isDeleted;
        for (auto &i: to_delete)
            isDeleted[i] = true;
        solve(root, isDeleted, ans);
        if(!isDeleted[root->val])
            ans.push_back(root);
        return ans;
    }

    void solve(TreeNode *node, unordered_map<int, bool> &isDeleted, vector<TreeNode *>& ans) {
        if (!node)
            return;
        solve(node->left, isDeleted, ans);
        solve(node->right, isDeleted, ans);
        if (isDeleted[node->val]) {
            if (node->left && !isDeleted[node->left->val]){
                ans.push_back(node->left);
                node->left = NULL;
            }
            if (node->right && !isDeleted[node->right->val]){
                ans.push_back(node->right);
                node->right = NULL;
            }
        }
        if(node->left && isDeleted[node->left->val])
            node->left = NULL;
        if(node->right && isDeleted[node->right->val])
            node->right = NULL;
    }
};