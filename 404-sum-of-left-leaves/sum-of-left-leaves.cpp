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
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root, false);
    }
    int solve(TreeNode* node, bool left){
        if(!node->left && !node ->right){
            if(left)
                return node->val;
            return 0;
        }
        int ret = 0;
        if(node->left)
            ret += solve(node->left, true);
        if(node->right)
            ret += solve(node->right, false);
        return ret;
    }
};